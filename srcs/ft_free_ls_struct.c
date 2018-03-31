/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ls_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:08:48 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/31 19:55:05 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	*ft_free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

/*
** Free t_str_stat structure and set all of it's elements to NULL
** Don't free ownr & ownr_grp as it's not malloced
*/

void	*ft_free_str_stat_struct(t_str_stats *t_s)
{
	if (t_s->name)
		t_s->name = ft_free_ptr(t_s->name);
	if (t_s->last_mod)
		t_s->last_mod = ft_free_ptr(t_s->last_mod);
	t_s = ft_free_ptr(t_s);
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
			de->s = ft_free_ptr(de->s);
		if (de->stats)
			de->stats = ft_free_str_stat_struct(de->stats);
		de = ft_free_ptr(de);
	}
}

/*
** Free string and stats of a cli param element
*/

void	ft_free_param_elem(t_param *e)
{
	if (e)
	{
		if (e->s)
			e->s = ft_free_ptr(e->s);
		if (e->stats)
			e->stats = ft_free_str_stat_struct(e->stats);
		e = ft_free_ptr(e);
	}
}

/*
** Free all color specifiers of a t_ls_color struct
*/

void	ft_free_colors(t_ls_colors *e)
{
	if (e)
	{
		e->di = ft_free_ptr(e->di);
		e->ln = ft_free_ptr(e->ln);
		e->so = ft_free_ptr(e->so);
		e->pi = ft_free_ptr(e->pi);
		e->ex = ft_free_ptr(e->ex);
		e->bd = ft_free_ptr(e->bd);
		e->cd = ft_free_ptr(e->cd);
		e->su = ft_free_ptr(e->su);
		e->sg = ft_free_ptr(e->sg);
		e->tw = ft_free_ptr(e->tw);
		e->ow = ft_free_ptr(e->ow);
		e = ft_free_ptr(e);
	}
}
