/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:34:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/26 19:13:05 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Apply colors on dir entries
*/

static char		*ft_get_color_str(t_str_stats *f)
{
	if (f->folder && *f->perms == 'd')
		return (DIR_COLOR);
	if (f->perms[3] == 'x' && !(*(f->perms) == 'l'))
		return (EXEC_COLOR);
	if (*(f->perms) == 'l')
		return (SYMLINK_COLOR);
	if (*(f->perms) == 'p')
		return (PIPE_COLOR);
	if (*(f->perms) == 'c')
		return (CHAR_SPE_COLOR);
	if (*(f->perms) == 'b')
		return (BLOCK_SPE_COLOR);
	return (NULL);
}

void			ft_colorize_name(t_str_stats *f)
{
	char	*ns;
	char	*col;
	int		name_len;

	ns = NULL;
	col = ft_get_color_str(f);
	if (col)
	{
		name_len = ft_strlen(f->name);
		ns = ft_strnew(name_len + ft_strlen(col) + 5);
		ft_strcpy(ns, col);
		ft_strcat(ns, f->name);
		ft_strcat(ns, COLOR_RESET);
		free(f->name);
		f->name = ns;
	}
}
