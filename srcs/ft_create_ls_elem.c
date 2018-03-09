/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ls_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:28:18 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 17:50:44 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Create a t_str_stat struct, set .name to s and init all other elements to NULL
*/

t_str_stats			*ft_create_str_stats_elem(char *s)
{
	t_str_stats		*f;

	f = malloc(sizeof(t_str_stats));
	if (!f)
	{
		ft_printf("ft_ls: malloc error\n");
		exit(1);
	}
	f->name = ft_strdup(s);
	f->folder = 0;
	f->perms = NULL;
	f->slnks = 0;
	f->ownr = NULL;
	f->ownr_grp = NULL;
	f->ownr_uid = 0;
	f->ownr_grp_uid = 0;
	f->size = 0;
	f->last_mod = NULL;
	f->rcode = -1;
	return (f);
}

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
