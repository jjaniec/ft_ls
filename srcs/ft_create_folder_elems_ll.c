/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_folder_elems_ll.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:22:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/17 22:09:30 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Create a sorted linked list containing all file/folder names
** sorted by (reverse(see $rev)) ascii values order
*/

t_dir_content		*ft_create_folder_elems_ll(char *path, int *dir_err, \
						t_args *args, int *total_blk)
{
	DIR				*d;
	struct dirent	*entry;
	t_dir_entry		*li;
	t_dir_entry		*tmp;
	t_dir_content	*r;

	entry = NULL;
	if (!(d = opendir(path)))
		return (ft_handle_dir_err(path, args, dir_err));
	r = ft_create_dir_content_s();
	li = NULL;
	while ((entry = readdir(d)) && ft_strlen(entry->d_name) > 0)
	{
		if (li && entry->d_name[0] && (entry->d_name[0] != '.' || \
			(entry->d_name[0] == '.' && args->opt && args->opt->a)))
		{
			tmp = ft_create_dir_entry_elem(entry->d_name, path, args, total_blk);
			li = ft_append_direntry(li, tmp, (args->opt) ? (args->opt->r) : (0));
		}
		else if (!li && entry->d_name[0] && (entry->d_name[0] != '.' || \
			(entry->d_name[0] == '.' && args->opt && args->opt->a)))
			li = ft_create_dir_entry_elem(entry->d_name, path, args, total_blk);
	}
	closedir(d);
	r->elems = li;
	return (r);
}
