/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ls_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:28:18 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/08 18:28:22 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Creates t_param elem with content passed as parameter and set next to null
*/

t_param				*ft_create_param_elem(char *s)
{
	t_param		*p;

	p = malloc(sizeof(t_param));
	p->s = s;
	p->next = NULL;
	return (p);
}
