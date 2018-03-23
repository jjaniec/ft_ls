/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:49:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/23 19:01:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Append to the linked list,
** a created t_param element with passed string as parameter:
**
** if (-r) and (-t) option are off,
** move forward in the linked list while the value of the parameter string is
** inferior of current element (ascii sort)
** if -t option is activated,
** compare epoch values of our new element and current element in linked list,
** and move forward while the epoch is >= of current element,
** if epoch values are the same,
** compare strings while it's the case.
** if the -r option is specified, do the same with inversed comparisons
**
** After place of current element was found, ft_append_elem add the element
** in the linked list, or if no inferior elements were found,
** set the new element as the first one and return it's address
*/

static void		ft_skip_elems(t_param **ptr, t_param **new, t_param **prev, \
					t_opt *opts)
{
	int			time_sort;
	int			rev;

	rev = (opts) ? (opts->r) : (0);
	time_sort = (opts) ? (opts->t) : (0);
	while ((*new) && (*ptr) && ((rev && \
		(((time_sort) ? (!((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch <= (*ptr)->stats->last_mod_epoch)) \
			: (0)) || \
		(((time_sort) ? (((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch == (*ptr)->stats->last_mod_epoch)) \
			: (1)) && \
			ft_strcmp((*ptr)->s, (*new)->s) > 0))) || \
		(!rev && \
		(((time_sort) ? (!((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch >= (*ptr)->stats->last_mod_epoch)) \
			: (0)) || \
		(((time_sort) ? (((*new)->stats && (*ptr)->stats && \
			(*new)->stats->last_mod_epoch == (*ptr)->stats->last_mod_epoch)) \
			: (1)) && \
			ft_strcmp((*ptr)->s, (*new)->s) < 0)))))
	{
		(*prev) = (*ptr);
		(*ptr) = (*ptr)->next;
	}
}

t_param			*ft_append_elem(t_param *li, t_param *new, t_opt *opts)
{
	t_param		*ptr;
	t_param		*prev;

	ptr = li;
	if (!new)
		return (li);
	prev = NULL;
	if (!new->stats)
		while (li && ptr && !li->stats && ft_strcmp(ptr->s, new->s) < 0)
		{
			prev = ptr;
			ptr = ptr->next;
		}
	else
		ft_skip_elems(&ptr, &new, &prev, opts);
	if (prev)
	{
		prev->next = new;
		new->next = ptr;
		return (li);
	}
	new->next = li;
	return (new);
}

/*
** Same functions for t_param elements
*/

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
	{
		*prev = *ptr;
		*ptr = (*ptr)->next;
	}
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
