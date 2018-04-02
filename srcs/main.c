/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/02 14:16:41 by jjaniec          ###   ########.fr       */
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
	args->cur_loop = 0;
	args->file_cli_args = 0;
	args->cur_epoch = time(NULL);
	params = NULL;
	args->opt = (ac > 1) ? (ft_parse_options(ac, av)) : (NULL);
	ft_init_colors(args);
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
}

/*
** Cycle through cli arguments, output files informations,
** and launch ft_ls_foreach_in_dir
** for each directory of the linked list args->prm
*/

static void		ft_start_ls_foreach_dir(t_args *args)
{
	t_param		*aptr;
	t_param		*prev;

	prev = NULL;
	aptr = args->prm;
	while (aptr)
	{
		if (aptr->stats && (aptr->stats->folder || \
			ft_ls_follow_symlink(aptr, args->opt)))
			ft_ls_foreach_in_dir(aptr->s, args);
		prev = aptr;
		aptr = aptr->next;
		args->cur_loop += 1;
		ft_free_param_elem(prev);
	}
}

void			ft_ls(t_args *args)
{
	t_param		*aptr2;

	aptr2 = args->prm;
	while (aptr2)
	{
		if (aptr2->stats && !aptr2->stats->folder && \
			!ft_ls_follow_symlink(aptr2, args->opt))
		{
			ft_ls_output_entry(aptr2->stats, args->opt);
			args->file_cli_args = 1;
		}
		aptr2 = aptr2->next;
	}
	ft_start_ls_foreach_dir(args);
}

/*
** Start function, init linked list of arguments in alphabetical
** or reverse alphabetical order (-r)
** and start ft_ls
*/

int				main(int ac, char **av)
{
	t_args	args;

	errno = 0;
	ft_init_args(ac, av, &args);
	if (args.prm)
		ft_ls(&args);
	ft_free_colors(args.cl);
	args.opt = ft_free_ptr(args.opt);
	return ((args.r));
}
