/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ls_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:08:48 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/16 19:24:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static	void	ft_free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

/*
** Free t_str_stat structure and set all of it's elements to NULL
*/

void	*ft_free_str_stat_struct(t_str_stats *t_s)
{
	if (t_s->name)
		ft_free_ptr(t_s->name);
	if (t_s->perms)
	{
		free(t_s->perms);
		t_s->perms = NULL;
	}
	if (t_s->ownr)
	{
		free(t_s->ownr);
		t_s->ownr = NULL;
	}
	if (t_s->ownr_grp)
	{
		free(t_s->ownr_grp);
		t_s->ownr_grp = NULL;
	}
	if (t_s->last_mod)
	{
		free(t_s->last_mod);
		t_s->last_mod = NULL;
	}
	free(t_s);
	t_s = NULL;
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
			ft_free_str_stat_struct(de->stats);
		free(de);
		de = NULL;
	}
}

/*
**
*/

void	ft_free_param_elem(t_param *e)
{
	if (e)
	{
		if (e->s)
			ft_free_ptr(e->s);
		if (e->stats)
			ft_free_str_stat_struct(e->stats);
		ft_free_ptr(e);
	}
}