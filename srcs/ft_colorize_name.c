/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:34:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/27 15:09:23 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Apply colors on dir entries with colors from $LS_COLORS
** environnement variable
*/

static char		*ft_get_color_str_env(t_str_stats *f, t_ls_colors *cl)
{
	if (!(f && f->perms))
		return (NULL);
	if (f->folder && f->perms[8] == 'w')
		return ((f->perms[9] == 't') ? (cl->tw) : (cl->ow));
	if (f->perms[3] == 's')
		return (cl->su);
	if (f->perms[6] == 's')
		return (cl->sg);
	if (f->folder && *f->perms == 'd')
		return (cl->di);
	if (*(f->perms) == 'l')
		return (cl->ln);
	if (*(f->perms) == 's')
		return (cl->so);
	if (*(f->perms) == 'p')
		return (cl->pi);
	if (*(f->perms) == 'b')
		return (cl->bd);
	if (*(f->perms) == 'c')
		return (cl->cd);
	if (f->perms[3] == 'x')
		return (cl->ex);
	return (NULL);
}

/*
** Apply colors on dir entries with default official colors
*/

static char		*ft_get_color_str_default(t_str_stats *f)
{
	if (f->folder && f->perms[8] == 'w')
		return ((f->perms[9] == 't') ? (DIR_WRITEOTHER_STICKY_COLOR) : \
			(DIR_WRITEOTHER_NOSTICKY_COLOR));
	if (f->perms[3] == 's')
		return (EXE_SETUID_COLOR);
	if (f->perms[6] == 's')
		return (EXE_SETGID_COLOR);
	if (f->folder && *f->perms == 'd')
		return (DIR_COLOR);
	if (*(f->perms) == 'l')
		return (SYMLINK_COLOR);
	if (*(f->perms) == 's')
		return (SOCKET_COLOR);
	if (*(f->perms) == 'p')
		return (PIPE_COLOR);
	if (*(f->perms) == 'b')
		return (BLOCK_SPE_COLOR);
	if (*(f->perms) == 'c')
		return (CHAR_SPE_COLOR);
	if (f->perms[3] == 'x')
		return (EXEC_COLOR);
	return (NULL);
}

void			ft_colorize_name(t_str_stats *f, t_ls_colors *cl)
{
	char	*ns;
	char	*col;
	int		name_len;

	ns = NULL;
	if (cl)
		col = ft_get_color_str_env(f, cl);
	else
		col = ft_get_color_str_default(f);
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
