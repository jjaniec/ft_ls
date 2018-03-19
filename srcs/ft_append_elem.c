/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:49:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/19 16:39:49 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Append to linked list, a created element with passed string as parameter
** todo verif si fichier/dossier existe et stop et print erreur si fichier non trouvé
*/

t_param			*ft_append_elem(t_param *li, t_param *prm, int rev)
{
	t_param		*ptr;
	t_param		*prev;

	ptr = li;
	if (!prm)
		return (li);
	prev = NULL;
	while (prm && ptr && \
		((rev && (ft_strcmp(ptr->s, prm->s) > 0)) || \
		(!rev && (ft_strcmp(ptr->s, prm->s) < 0))))
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (prev)
	{
		prev->next = prm;
		prm->next = ptr;
		return (li);
	}
	prm->next = li;
	return (prm);
}

t_dir_entry		*ft_append_direntry(t_dir_entry *li, t_dir_entry *new, t_opt *opts)
{
	t_dir_entry		*ptr;
	t_dir_entry		*prev;
	int				rev;
	int				time_sort;

	rev = (opts) ? (opts->r) : (0);
	time_sort = (opts) ? (opts->t) : (0);
	ptr = li;
	prev = NULL;
	while (ptr && \
		((rev && (((time_sort) ? (new->stats->last_mod_epoch > ptr->stats->last_mod_epoch) : (1)) || \
			((!time_sort) && (*__OS__ == 'L' || ft_strcmp(ptr->s, new->s) > 0)))) || \
		(!rev && (((time_sort) ? (new->stats->last_mod_epoch < ptr->stats->last_mod_epoch) : (1)) || \
			((!time_sort) && (*__OS__ == 'L' || ft_strcmp(ptr->s, new->s) < 0))))))
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (prev)
	{
		prev->next = new;
		new->next = ptr;
		return (li);
	}
	new->next = li;
	return (new);
}