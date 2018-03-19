/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:32:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/19 23:21:19 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prints infos of directory entry dependending of command line options
*/

void	ft_ls_output_entry(t_str_stats *de, t_opt *opts)
{
	if (opts)
	{
		if (opts->l && !opts->n)
			PRINTF("%s  %2d %-7s %-8s %8d %s %s\n", de->perms, de->slnks, \
			de->ownr, de->ownr_grp, de->size, de->last_mod, de->name);
		if (opts->l && opts->n)
			PRINTF("%s  %2d %-5u %-4u %8d %s %s\n", de->perms, de->slnks, \
			de->ownr_uid, de->ownr_grp_uid, de->size, de->last_mod, de->name);
	}
	if (!opts || !opts->l)
		PRINTF("%s\n", de->name);
}