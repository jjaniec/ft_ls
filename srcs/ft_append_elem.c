/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:49:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/07 17:49:40 by jjaniec          ###   ########.fr       */
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
	rev = 0;
	prev = NULL;
	while (ptr && ((rev == 0 && (ft_strcmp(ptr->s, prm->s) > 0)) || \
		(rev == 1 && (ft_strcmp(ptr->s, prm->s) < 0))))
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