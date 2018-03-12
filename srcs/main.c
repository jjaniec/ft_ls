/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/12 23:22:42 by jjaniec          ###   ########.fr       */
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
** Create a sorted linked list containing all file/folder names
** sorted by ascii values
*/

t_param				*ft_ls_create_filesll(char *path, int rev)
{
	DIR				*d;
	struct dirent 	*entry;
	t_param			*li;
	t_param			*tmp;

	d = opendir(path);
	li = NULL;
	if (d)
	{
		while ((entry = readdir(d)))
			if (!(entry->d_name[0] == '.'))
			{
				if (li)
				{
					tmp = ft_create_param_elem(entry->d_name);
					li = ft_append_elem(li, tmp, rev);
				}
				else
					ft_init_params_list(&li, entry->d_name);
			}
	}
	//ft_debug_prm(li);
	return (li);
}

/*
** Recursive part
*/

void	ft_ls_foreach_in_dir(char *s, t_opt *opts)
{
	t_param			*li;
	t_param			*ptr;
	t_str_stats		*st;
	char			*ns;

	li = ft_ls_create_filesll(s, (opts) ? (opts->r) : (0));
	ptr = li;
	ft_printf("%s:\n", s);
	while (ptr)
	{
		ns = ft_strjoin_path(s, ptr->s);
		st = ft_get_stats(ns, opts);
		if (st)
			ft_printf("%s - %s\n", st->perms, ptr->s);
		ptr = ptr->next;
	}
	while (li)
	{
		ns = ft_strjoin_path(s, li->s);
		st = ft_get_stats(ns, opts);
		//ft_debug_str_stats(ns, st, opts);
		//ft_debug_str_stats(li->s, st, opts);
		if (st && opts && st->folder && opts->r_caps)
			ft_ls_foreach_in_dir(ft_strdup(ns), opts);
		free(ns);
		free(st);
		ptr = li;
		li = li->next;
		free(ptr);
	}
	(terpri);
}

/*
** Cycle through cli arguments and launch ft_ls_foreach_in_dir
** for each element of the linked list args.aptr
*/

void	ft_ls(t_args args)
{
	t_param		*aptr;
	t_param		*prev;
	t_str_stats	*infs;

	aptr = args.prm;
	while (aptr)
	{
		infs = ft_get_stats(aptr->s, args.opt);
		ft_debug_str_stats(aptr->s, infs, args.opt);
		if (infs && infs->folder)
			ft_ls_foreach_in_dir(aptr->s, args.opt);
		prev = aptr;
		aptr = aptr->next;
		free(prev);
		free(infs);
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
