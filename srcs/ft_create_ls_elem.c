/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ls_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:28:18 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/30 16:14:25 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Creates t_param elem with content passed as parameter and set next to null
*/

t_param				*ft_create_param_elem(char *s, t_args *args, int *r)
{
	t_param		*p;

	p = malloc(sizeof(t_param));
	p->s = ft_strdup(s);
	p->stats = ft_get_stats(p->s, args, s);
	if (!p->stats)
	{
		*r = 1;
		if (*__OS__ == 'L')
		{
			ft_handle_not_found_err(s);
			ft_free_ptr(p);
			return (NULL);
		}
		p->s = ft_strdup(s);
	}
	p->next = NULL;
	return (p);
}

/*
** Create a t_str_stat struct, set .name to s
** and init all other elements to NULL
*/

t_str_stats			*ft_create_str_stats_elem(char *s)
{
	t_str_stats		*f;

	f = malloc(sizeof(t_str_stats));
	if (!f)
	{
		PRINTF("ft_ls: malloc error\n");
		exit(1);
	}
	f->name = s;
	f->folder = 0;
	f->perms_attr_acl = ' ';
	f->slnks = 0;
	f->ownr = NULL;
	f->ownr_grp = NULL;
	f->ownr_uid = 0;
	f->ownr_grp_uid = 0;
	f->size = 0;
	f->last_mod = NULL;
	f->last_mod_epoch = 0;
	f->rcode = 0;
	return (f);
}

/*
** Creates a t_dir_entry elem, store stats of elem in elem->stats and return
** it's address
*/

t_dir_entry			*ft_create_dir_entry_elem(char *s, char *path, \
						t_args *args, int *total_blk)
{
	t_dir_entry		*e;
	char			*ns;

	e = malloc(sizeof(t_dir_entry));
	e->s = ft_strdup(s);
	ns = ft_strjoin_path(ft_strdup(path), ft_strdup(s));
	e->stats = ft_get_stats(ns, args, s);
	if (ns && e->stats)
		*total_blk += e->stats->size_blocks;
	if (e->stats)
		ns = ft_free_ptr(ns);
	e->next = NULL;
	return (e);
}

/*
** Creates a t_dir_content struct to store all elements of a directory
** init the total blocks count to 0 and return address of created element
*/

t_dir_content		*ft_create_dir_content_s(void)
{
	t_dir_content		*r;

	r = malloc(sizeof(t_dir_content));
	r->c = 0;
	r->elems = NULL;
	r->blocks_total = 0;
	return (r);
}
