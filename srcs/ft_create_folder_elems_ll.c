/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_folder_elems_ll.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:22:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/15 15:22:02 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Creates linked list's first argument
*/

static void			*ft_init_folder_elems_ll(\
						t_dir_entry **initptr, t_opt *opts, char *s, char *path)
{
	t_dir_entry		*t;

	t = ft_create_dir_entry_elem(ft_strdup(s), path, opts);
	*initptr = t;
	return (t);
}

/*
** Create a sorted linked list containing all file/folder names
** sorted by (reverse(see $rev)) ascii values order
*/

t_dir_content		*ft_create_folder_elems_ll(char *path, int rev, \
						t_opt *opts, int *total_blk)
{
	DIR				*d;
	struct dirent	*entry;
	t_dir_entry		*li;
	t_dir_entry		*tmp;
	t_dir_content	*r;

	entry = NULL;
	r = ft_create_dir_content_s();
	d = opendir(path);
	li = NULL;
	if (d)
		while ((entry = readdir(d)))
		{
			if (li)
			{
				tmp = ft_create_dir_entry_elem(entry->d_name, path, opts);
				li = ft_append_direntry(li, tmp, rev);
				*total_blk += tmp->stats->size_blocks;
			}
			else if (!li && (entry->d_name[0] != '.' || \
				(entry->d_name[0] == '.' && opts && opts->a)))
				ft_init_folder_elems_ll(&li, opts, entry->d_name, path);
		}
	r->elems = li;
	return (r);
}
