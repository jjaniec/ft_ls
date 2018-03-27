/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_folder_elems_ll.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:22:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/27 15:20:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int			ft_is_cur_prev_dir(char *s)
{
	if (s[0] == '.' && (!s[1] || (s[1] == '.' && !s[2])))
		return (1);
	return (0);
}

/*
** Create a sorted linked list containing all file/folder names
** sorted by (reverse(see $rev)) ascii values order
*/

t_dir_content		*ft_create_folder_elems_ll(char *path, int *dir_err, \
						t_args *args)
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
		if (entry->d_name[0] && !(entry->d_name[0] == '.' && \
			!(args->opt && (args->opt->a || args->opt->a_caps))) && \
			!(args->opt->a_caps && !args->opt->a && \
				ft_is_cur_prev_dir(entry->d_name)))
		{
			tmp = ft_create_dir_entry_elem(entry->d_name, path, args, \
				&(r->blocks_total));
			li = (li) ? \
				(ft_append_direntry(li, tmp, args->opt)) : (tmp);
		}
	closedir(d);
	r->elems = li;
	return (r);
}
