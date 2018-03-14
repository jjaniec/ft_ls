/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:54:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/14 15:28:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Read stats from passed char * and return a t_str_stats containing infos
** required for -l output of $arg file
*/

t_str_stats		*ft_get_stats_l_opt(\
		t_str_stats *f, struct stat *f_stats, t_opt *opts)
{
	f->slnks = f_stats->st_nlink;
	ft_fill_owners(f, f_stats, opts);
	f->size = f_stats->st_size;
	ft_fill_last_mod(f, f_stats);
	return (f);
}

/*
** Read stats from passed char * and return a t_str_stats struct containing
** name and sets str_stats.folder to 1 if $s is a folder
*/

t_str_stats		*ft_get_stats(char *path, t_opt *opt, char *name)
{
	struct stat		arg_stats;
	t_str_stats		*f;

	f = ft_create_str_stats_elem(path);
	f->rcode = lstat(path, &arg_stats);
	if (f->rcode < 0)
		return (ft_free_str_stat_struct(f));
	f->name = name;
	if (S_ISDIR(arg_stats.st_mode))
		f->folder = TRUE;
	ft_fill_perms(f, &arg_stats);
	if (opt && opt->g_caps)
		ft_colorize_name(f);
	if (opt && opt->l)
		return (ft_get_stats_l_opt(f, &arg_stats, opt));
	return (f);
}
