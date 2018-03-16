/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_folder_elems_ll.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:22:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/16 15:01:46 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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
	d = opendir(path);
	if (!d)
		return (NULL);
	r = ft_create_dir_content_s();
	li = NULL;
	while ((entry = readdir(d)) && ft_strlen(entry->d_name) > 0)
	{
		if (li && entry->d_name[0] && (entry->d_name[0] != '.' || \
			(entry->d_name[0] == '.' && opts && opts->a)))
		{
			tmp = ft_create_dir_entry_elem(entry->d_name, path, opts, total_blk);
			li = ft_append_direntry(li, tmp, rev);
		}
		else if (!li && entry->d_name[0] && (entry->d_name[0] != '.' || \
			(entry->d_name[0] == '.' && opts && opts->a)))
			li = ft_create_dir_entry_elem(entry->d_name, path, opts, total_blk);
	}
	closedir(d);
	r->elems = li;
	return (r);
}
