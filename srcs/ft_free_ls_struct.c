/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ls_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:08:48 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 17:51:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Free t_str_stat structure and set all of it's elements to NULL
*/

void	*ft_free_str_stat_struct(t_str_stats *t_s)
{
	free(t_s->name);
	free(t_s->perms);
	if (t_s->ownr)
		free(t_s->ownr);
	if (t_s->ownr_grp)
		free(t_s->ownr_grp);
	if (t_s->last_mod)
		free(t_s->last_mod);
	return (NULL);
}