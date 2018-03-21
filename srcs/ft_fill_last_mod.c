/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_last_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:13:17 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/21 15:50:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Takes last modification information and format it like the ls -l option does
*/

void		ft_fill_last_mod(t_str_stats *f, struct stat *f_stats, t_args *args)
{
	char			*s;
	char			*sr;
	unsigned long	six_months_epoch;

	sr = ft_strnew(12);
	f->last_mod_epoch = f_stats->st_mtime;
	s = ctime(&(*f_stats).st_mtime);
	six_months_epoch = args->cur_epoch - (86400 * 30 * 6);
	if (!(six_months_epoch > f->last_mod_epoch))
	{
		ft_strncpy(sr, s + 4, 12);
	}
	else
	{
		ft_strncpy(sr, s + 4, 7);
		ft_strncpy(sr + 7, s + 15 + 4, 5);
	}
	f->last_mod = sr;
}