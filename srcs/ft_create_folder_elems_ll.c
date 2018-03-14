/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_folder_elems_ll.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:22:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/14 16:23:48 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Creates linked list's first argument
*/

static void			*ft_init_folder_elems_ll(\
						t_dir_entry **initptr, char *s)
{
	t_dir_entry		*t;

	t = ft_create_dir_entry_elem(ft_strdup(s));
	*initptr = t;
	return (t);
}

/*
** Create a sorted linked list containing all file/folder names
** sorted by (reverse(see $rev)) ascii values order
*/

t_dir_content		*ft_create_folder_elems_ll(char *path, int rev, t_opt *opts)
{
	DIR				*d;
	struct dirent	*entry;
	t_dir_entry		*li;
	t_dir_entry		*tmp;
	t_dir_content	*r;

	entry = NULL;
	tmp = NULL;
	r = ft_create_dir_content_s();
	d = opendir(path);
	li = NULL;
	if (d)
	{
		while ((entry = readdir(d)))
			if (li)
			{
				tmp = ft_create_dir_entry_elem(entry->d_name);
				li = ft_append_direntry(li, tmp, rev);
			}
			else if (!li && (entry->d_name[0] != '.' || \
				(entry->d_name[0] == '.' && opts && opts->a)))
				ft_init_folder_elems_ll(&li, entry->d_name);
	}
	r->elems = li;
	return (r);
}
