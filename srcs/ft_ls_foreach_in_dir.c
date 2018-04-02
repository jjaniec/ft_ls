/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_foreach_in_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:41:53 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/02 13:42:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recursive part, create linked list of dir $s entries, print
** it's content and search for other directories in it,
** if a new directory is found call ft_recurse_to_dir to repeat
** ft_ls_foreach_in_dir with new path
*/

static void		ft_recurse_to_dir(char *path, char *entry, t_args *args)
{
	char		*ns;

	ns = ft_strjoin_path(ft_strdup(path), ft_strdup(entry));
	ft_ls_foreach_in_dir(ns, args);
	ft_free_ptr(ns);
}

void			ft_ls_foreach_in_dir(char *s, t_args *args)
{
	t_dir_content	*dc;
	t_dir_entry		*li;
	int				dir_err;
	t_dir_entry		*ptr;

	dir_err = 0;
	dc = ft_create_folder_elems_ll(s, &dir_err, args);
	if (dc)
	{
		li = dc->elems;
		ft_ls_output_dir_elems(dc, &dir_err, args, s);
		while (li)
		{
			if (li && li->s && li->stats && li->stats->folder && \
				args->opt && args->opt->r_caps && ft_can_recurse(li))
				ft_recurse_to_dir(s, li->s, args);
			ptr = li->next;
			ft_free_dir_entry(li);
			li = ptr;
		}
		ft_free_dir_entry(li);
		ft_free_ptr(dc);
	}
}