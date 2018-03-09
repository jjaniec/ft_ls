/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:54:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 16:19:07 by jjaniec          ###   ########.fr       */
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
	ft_fill_perms(f, f_stats);
	f->slnks = f_stats->st_nlink;
	ft_fill_owners(f, f_stats);
	return (f);
}

/*
** Read stats from passed char * and return a t_str_stats struct containing
** name and sets str_stats.folder to 1 if $s is a folder
*/

t_str_stats		*ft_get_stats(char *s, t_opt *opt)
{
	struct stat		arg_stats;
	t_str_stats		*f;

	f = ft_create_str_stats_elem(s);
	f->rcode = lstat(s, &arg_stats);
	if (f->rcode < 0)
		return (ft_free_str_stat_struct(f));
	f->name = s;
	if (S_ISDIR(arg_stats.st_mode))
		f->folder = TRUE;
	if (opt && opt->l)
		return (ft_get_stats_l_opt(f, &arg_stats, opt));
	return (f);
}
