/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_direntry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:48:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/26 16:44:42 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Same functions of ft_append_elem.c for t_param elements
*/

static void		ft_goto_next(t_dir_entry **ptr, t_dir_entry **prev)
{
		*prev = *ptr;
		*ptr = (*ptr)->next;
}

static void		ft_skip_direntries(t_dir_entry **ptr, t_dir_entry **new, \
					t_dir_entry **prev, t_opt *opts)
{
	int			time_sort;
	int			rev;

	rev = (opts) ? (opts->r) : (0);
	time_sort = (opts) ? (opts->t) : (0);
	while (*new && *ptr && ((rev && \
		(((time_sort) ? (!((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch <= (*ptr)->stats->last_mod_epoch)) \
			: (0)) || \
		(((time_sort) ? (((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch == (*ptr)->stats->last_mod_epoch)) \
			: (1)) && ft_strcmp((*ptr)->s, (*new)->s) > 0))) || \
		(!rev && \
		(((time_sort) ? (!((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch >= (*ptr)->stats->last_mod_epoch)) \
			: (0)) || \
		(((time_sort) ? (((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch == (*ptr)->stats->last_mod_epoch)) \
			: (1)) && \
			ft_strcmp((*ptr)->s, (*new)->s) < 0)))))
		ft_goto_next(ptr, prev);
}

static void		ft_skip_direntries_alphacmp(t_dir_entry **ptr, t_dir_entry **new, \
					t_dir_entry **prev, int rev)
{
	if (rev && (*new) && (*ptr))
		while (*ptr && ft_ls_str_alphacmp((*ptr)->s, (*new)->s) > 0)
			ft_goto_next(ptr, prev);
	else if (!rev && (*new) && (*ptr))
		while (*ptr && (ft_ls_str_alphacmp((*ptr)->s, (*new)->s) < 0))
			ft_goto_next(ptr, prev);
}

t_dir_entry		*ft_append_direntry(t_dir_entry *li, t_dir_entry *new, \
					t_opt *opts)
{
	t_dir_entry		*ptr;
	t_dir_entry		*prev;

	if (!new)
		return (li);
	ptr = li;
	prev = NULL;
	if (*__OS__ == 'L' && !(opts->t))
		ft_skip_direntries_alphacmp(&ptr, &new, &prev, (opts) ? (opts->r) : (0));
	else
		ft_skip_direntries(&ptr, &new, &prev, opts);
	if (prev)
	{
		prev->next = new;
		new->next = ptr;
		return (li);
	}
	new->next = li;
	return (new);
}