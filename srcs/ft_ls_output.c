/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:32:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/28 17:43:09 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prints infos of directory entry dependending of command line options
*/

static void		ft_ls_output_no_n_opt(t_str_stats *de)
{
	if (*de->perms == 'b' || *de->perms == 'c')
		PRINTF("%s%c %3d %-10s %-10s %3u, %4u %s %s\n", de->perms, \
			de->perms_attr_acl, de->slnks, de->ownr, \
			de->ownr_grp, de->rdev_maj, de->rdev_min, de->last_mod, de->name);
	else
	{
		if (de->ownr && de->ownr_grp)
			PRINTF("%s%c %3d %-10s %-10s %9d %s %s\n", de->perms, \
				de->perms_attr_acl, de->slnks, de->ownr, \
				de->ownr_grp, de->size, de->last_mod, de->name);
		else if (!de->ownr || !de->ownr_grp)
		{
			PRINTF("%s%c %3d", de->perms, de->perms_attr_acl, de->slnks);
			if (de->ownr)
				PRINTF(" %-10s", de->ownr);
			else
				PRINTF(" %10u", de->ownr_uid);
			if (de->ownr_grp)
				PRINTF(" %-10s", de->ownr_grp);
			else
				PRINTF(" %10u", de->ownr_grp_uid);
			PRINTF(" %9d %s %s\n", de->size, de->last_mod, de->name);
		}
	}
}

void			ft_ls_output_entry(t_str_stats *de, t_opt *opts)
{
	if (opts && de && opts->l)
	{
		if (!opts->n)
			ft_ls_output_no_n_opt(de);
		else
			PRINTF("%s%c %3d %10u %10u %9d %s %s\n", de->perms, \
				de->perms_attr_acl, de->slnks, de->ownr_uid, \
				de->ownr_grp_uid, de->size, de->last_mod, de->name);
	}
	else if (de && !(opts && opts->l))
		PRINTF("%s\n", de->name);
}
