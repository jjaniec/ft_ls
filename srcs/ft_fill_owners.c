/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_owners.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:13:14 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 17:39:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Get owners uid/name and owner group of f
*/

void	ft_fill_owners(t_str_stats *f, struct stat *f_stats, t_opt *opts)
{
	struct passwd	*pwd;
	struct group	*pwd_grp;

	f->ownr_uid = f_stats->st_uid;
	f->ownr_grp_uid = f_stats->st_gid;
	if (!opts->n)
	{
		if ((pwd = getpwuid(f->ownr_uid)))
			f->ownr = pwd->pw_name;
		if ((pwd_grp = getgrgid(f->ownr_grp_uid)))
			f->ownr_grp = pwd_grp->gr_name;
	}
}