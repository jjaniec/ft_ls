/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_follow_symlink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:22:20 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/01 00:12:49 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Determine if ft_ls should print symlink (0) or print content of directory
** pointed by the symlink
*/

int		ft_ls_follow_symlink(t_param *e, t_opt *opts)
{
	struct stat		a;

	if (e->stats && e->stats->perms[0] == 'l')
	{
		if (!(stat(e->s, &a) < 0))
		{
			if (opts && opts->l)
				return (0);
			else
				return (1);
		}
	}
	return (0);
}
