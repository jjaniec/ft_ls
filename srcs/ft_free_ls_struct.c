/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ls_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:08:48 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/16 18:47:53 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Free t_str_stat structure and set all of it's elements to NULL
*/

void	*ft_free_str_stat_struct(t_str_stats *t_s)
{
	if (t_s->name)
	{
		free(t_s->name);
		t_s->name = NULL;
	}
	if (t_s->perms)
		free(t_s->perms);
	if (t_s->ownr)
		free(t_s->ownr);
	if (t_s->ownr_grp)
		free(t_s->ownr_grp);
	if (t_s->last_mod)
		free(t_s->last_mod);
	return (NULL);
}

/*
** Free all content of a dir_entry struct pointer and set the pointer to NULL
*/

void	ft_free_dir_entry(t_dir_entry *de)
{
	if (de)
	{
		if (de->s)
		{
			free(de->s);
			de->s = NULL;
		}
		if (de->stats)
		{
			free(de->stats);
			de->stats = NULL;
		}
		free(de);
		de = NULL;
	}
}