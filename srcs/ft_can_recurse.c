/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_recurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:12:27 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/15 22:20:50 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Return 0 if strcmp($s, ".") == 0 || strcmp($s, "..") == 0
** otherwise return 1
*/

int		ft_can_recurse(t_dir_entry *e)
{
	if (e->s && e->s[0] == '.' && e->stats && e->stats->perms && *(e->stats->perms) != 'l')
	{
		if (!(e->s[1]) || ft_strcmp(e->s, "..") == 0)
			return (0);
	}
	return (1);
}