/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:54:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/08 20:41:05 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Read stats from passed char * and return a t_str_stats containing infos
** required for -l output of $arg file
*/

t_str_stats		*ft_get_stats_l_opt(char *arg, struct stat *f_stats, t_opt *opts)
{
	return (NULL);
}

/*
** Read stats from passed char * and return a t_str_stats struct containing
** name and sets str_stats.folder to 1 if $arg is a folder
*/

t_str_stats		*ft_get_stats(char *arg, t_opt *opt)
{
	struct stat		arg_stats;
	t_str_stats		*f;

	f = ft_create_str_stats_elem(arg);
	f->rcode = lstat(arg, &arg_stats);
	if (f->rcode < 0)
		return (NULL);
	f->name = arg;
	if (opt && opt->l)
		return (ft_get_stats_l_opt(arg, &arg_stats, opt));
	if (S_ISDIR(arg_stats.st_mode))
		f->folder = TRUE;
	return (f);
}
