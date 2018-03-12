/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/12 14:49:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Init a t_args struct containing options in a t_opt struct and
** a pointer on a linked list containing all files/folder names of type t_param
*/

void		ft_init_args(int ac, char **av, t_args *args)
{
	t_opt	*opts;
	t_param	*params;

	opts = NULL;
	params = NULL;
	opts = (ac > 1) ? (ft_parse_options(ac, av)) : (NULL);
	if (opts)
		params = (ac > 2) ? \
		(ft_parse_params(ac, av, opts->r)) : (ft_create_param_elem("."));
	else
		params = (ac > 1) ? \
		(ft_parse_params(ac, av, 0)) : (ft_create_param_elem("."));
	args->opt = opts;
	args->prm = params;
}

/*
** Recursive part,
** first two readdir are here to skip . & ..
*/

void	ft_ls_foreach_in_dir(char *s, t_opt *opts)
{
	DIR				*d;
	struct dirent 	*dir;
	t_str_stats		*st;
	char			*ns;

	d = opendir(s);
	if (d)
	{
		dir = readdir(d);
		dir = readdir(d);
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", s);
			ns = ft_strjoin(ft_strjoin(s, "/"), dir->d_name);
			st = ft_get_stats(ns, opts);
			ft_debug_str_stats(ns, st, opts);
			if (st && st->folder && opts && opts->r_caps && st->name[0] != '.' && s[0] != '.')
				ft_ls_foreach_in_dir(ns, opts);
		}
		closedir(d);
	}
}

/*
** Cycle through cli arguments and launch ft_ls_foreach_in_dir
** for each element of the linked list args.aptr
*/

void	ft_ls(t_args args)
{
	t_param		*aptr;
	t_str_stats	*infs;

	aptr = args.prm;
	while (aptr)
	{
		infs = ft_get_stats(aptr->s, args.opt);
		ft_debug_str_stats(aptr->s, infs, args.opt);
		if (infs && infs->folder)
			ft_ls_foreach_in_dir(aptr->s, args.opt);
		aptr = aptr->next;
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
	ft_ls(args);
	return (0);
}
