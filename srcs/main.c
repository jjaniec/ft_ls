/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/26 21:12:03 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Init a t_args struct containing options in a t_opt struct and
** a pointer on a linked list containing all files/folder names of type t_param
*/

static void		ft_init_args(int ac, char **av, t_args *args)
{
	t_param	*params;
	t_param *ptr;

	args->r = 0;
	args->prm_len = 0;
	args->file_cli_args = 0;
	args->cur_epoch = time(NULL);
	params = NULL;
	args->opt = (ac > 1) ? (ft_parse_options(ac, av)) : (NULL);
	params = (ac > 1) ? (ft_parse_params(ac, av, args)) : \
						(ft_create_param_elem(".", args, &(args->r)));
	if (!params && !(args->r))
		params = ft_create_param_elem(".", args, &(args->r));
	ptr = params;
	if (*__OS__ == 'D' || *__OS__ == '?')
		while (ptr && ptr->s)
		{
			if (!(ptr->stats))
				ft_handle_not_found_err(ptr->s);
			ptr = ptr->next;
		}
	args->prm = params;
	ft_init_colors(args);
}

/*
** Recursive part, create linked list of dir $s entries, print
** it's content and search for other directories in it,
** if a new directory is found call ft_recurse_to_dir to repeat
** ft_ls_foreach_in_dir with new path
*/

static void		ft_recurse_to_dir(char *path, char *entry, t_args *args)
{
	char		*ns;

	ns = ft_strjoin_path(ft_strdup(path), ft_strdup(entry));
	ft_ls_foreach_in_dir(ns, args);
	ft_free_ptr(ns);
}

void			ft_ls_foreach_in_dir(char *s, t_args *args)
{
	t_dir_content	*dc;
	t_dir_entry		*li;
	int				dir_err;
	t_dir_entry		*ptr;

	dir_err = 0;
	dc = ft_create_folder_elems_ll(s, &dir_err, args);
	if (dc)
	{
		li = dc->elems;
		ft_ls_output_dir_elems(dc, &dir_err, args, s);
		while (li)
		{
			if (li && li->s && li->stats && li->stats->folder && \
				args->opt && args->opt->r_caps && ft_can_recurse(li))
				ft_recurse_to_dir(s, li->s, args);
			ptr = li->next;
			ft_free_dir_entry(li);
			li = ptr;
		}
		ft_free_dir_entry(li);
		ft_free_ptr(dc);
	}
}

/*
** Cycle through cli arguments and launch ft_ls_foreach_in_dir
** for each element of the linked list args.aptr
*/

void			ft_ls(t_args args)
{
	t_param		*aptr;
	t_param		*aptr2;
	t_param		*prev;

	prev = NULL;
	aptr = args.prm;
	aptr2 = aptr;
	while (aptr2)
	{
		if (aptr2->stats && !aptr2->stats->folder)
		{
			ft_ls_output_entry(aptr2->stats, args.opt);
			args.file_cli_args = 1;
		}
		aptr2 = aptr2->next;
	}
	while (aptr)
	{
		if (aptr->stats && aptr->stats->folder)
			ft_ls_foreach_in_dir(aptr->s, &args);
		prev = aptr;
		aptr = aptr->next;
		ft_free_param_elem(prev);
	}
}

/*
** Start function, init linked list of arguments in alphabetical
** or reverse alphabetical order (-r)
** and start ft_ls
*/

int				main(int ac, char **av)
{
	t_args	args;

	ft_init_args(ac, av, &args);
	ft_debug_ls_colors(args.cl);
	if (args.prm)
		ft_ls(args);
	ft_free_colors(args.cl);
	ft_free_ptr(args.opt);
	return ((args.r));
}
