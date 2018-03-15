/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/15 14:01:14 by jjaniec          ###   ########.fr       */
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

	args->r = 0;
	params = NULL;
	args->opt = (ac > 1) ? (ft_parse_options(ac, av)) : (NULL);
	if (args->opt)
		params = (ac > 2) ? (ft_parse_params(ac, av, args)) : \
							(ft_create_param_elem(".", args->opt, &(args->r)));
	else
		params = (ac > 1) ? (ft_parse_params(ac, av, args)) : \
							(ft_create_param_elem(".", args->opt, &(args->r)));
	if (!params && !(args->r))
		params = ft_create_param_elem(".", args->opt, &(args->r));
	args->prm = params;
}

/*
** Recursive part
*/

static void		ft_ls_foreach_in_dir(char *s, t_opt *opts)
{
	t_dir_content	*dc;
	t_dir_entry		*li;
	t_dir_entry		*ptr;
	char			*ns;

	dc = ft_create_folder_elems_ll(s, (opts) ? (opts->r) : (0), opts);
	li = (dc) ? (dc->elems) : (NULL);
	ptr = li;
	//ft_debug_dir_content(dc, opts);
	ft_printf("%s:\n", s);
	while (ptr)
	{
		ns = ft_strjoin_path(ft_strdup(s), ft_strdup(ptr->s));
		ptr->stats = ft_get_stats(ns, opts, ft_strdup(ptr->s));
		if (ptr->stats)
			ft_ls_output_entry(ptr->stats, opts);
		ptr = ptr->next;
	}
	(terpri);
	while (li)
	{
		if (li && li->stats && opts && li->stats->folder && opts->r_caps && ft_can_recurse(li->s))
		{
			ns = ft_strjoin_path(ft_strdup(s), ft_strdup(li->s));
			ft_ls_foreach_in_dir(ft_strdup(ns), opts);
			free(ns);
		}
		ptr = li;
		li = li->next;
		free(ptr);
	}
	//free(dc);
}

/*
** Cycle through cli arguments and launch ft_ls_foreach_in_dir
** for each element of the linked list args.aptr
*/

void		ft_ls(t_args args)
{
	t_param		*aptr;
	t_param		*prev;

	prev = NULL;
	aptr = args.prm;
	while (aptr)
	{
		ft_debug_str_stats(aptr->s, aptr->stats, args.opt);
		if (aptr->stats && aptr->stats->folder)
			ft_ls_foreach_in_dir(aptr->s, args.opt);
		prev = aptr;
		aptr = aptr->next;
		free(prev);
	}
}

/*
** Start function, init linked list of arguments in alphabetical
** or reverse alphabetical order (-r)
** and start ft_ls
*/

int		main(int ac, char **av)
{
	t_args	args;

	ft_init_args(ac, av, &args);
	ft_debug_ls_args(args);
	if (args.prm)
		ft_ls(args);
	return ((args.r));
}
