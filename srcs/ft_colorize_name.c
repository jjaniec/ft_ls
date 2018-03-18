/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:34:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/18 19:19:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Apply colors on file/folder name:
** red: executable
** magenta: folder
*/

void	ft_colorize_name(t_str_stats *f)
{
	char	*s;

	s = NULL;
	if (f->perms && (f->folder || f->perms[3] == 'x' || *(f->perms) != 'l'))
	{
		if (f->folder)
			s = ft_strjoin_free(ft_strdup(DIR_COLOR), ft_strdup(f->name));
		else if (f->perms[3] == 'x' && !(*(f->perms) == 'l'))
			s = ft_strjoin_free(ft_strdup(EXEC_COLOR), ft_strdup(f->name));
		else if (*(f->perms) == 'l')
			s = ft_strjoin_free(ft_strdup(SYMLINK_COLOR), ft_strdup(f->name));
		if (s)
		{
			free(f->name);
			f->name = ft_strjoin(s, FG_WHITE);
			free(s);
		}
		else
			free(s);
	}
}