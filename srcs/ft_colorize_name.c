/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:34:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/25 18:09:25 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Apply colors on dir entries
*/

static char		*ft_get_color_str(t_str_stats *f)
{
	char	*ns;
	char	*tmp;

	ns = "";
	tmp = NULL;
	if (f->folder && *f->perms == 'd')
		ns = ft_strjoin(ns, DIR_COLOR);
	else if (f->perms[3] == 'x' && !(*(f->perms) == 'l'))
		ns = ft_strjoin(ns, EXEC_COLOR);
	else if (*(f->perms) == 'l')
		ns = ft_strjoin(ns, SYMLINK_COLOR);
	else if (*(f->perms) == 'p')
		ns = ft_strjoin(ns, FIFO_COLOR);
	else if (*(f->perms) == 'c' || *(f->perms) == 'b')
	{
		tmp = ft_strjoin(ns, SPECIAL_COLOR);
		ns = ft_strjoin(tmp, (*(f->perms) == 'b') ? \
			(BLOCK_SPE_BG_COLOR) : (CHAR_SPE_BG_COLOR));
		ft_free_ptr(tmp);
	}
	return (ns);
}

void			ft_colorize_name(t_str_stats *f)
{
	char	*s;
	char	*ns;
	size_t	s_l;
	size_t	name_l;
	int		def_l[2];

	ns = NULL;
	s = NULL;
	if (f->perms && (*(f->perms) != '-' || f->perms[3] == 'x') && \
		(s = ft_get_color_str(f)))
	{
		s_l = ft_strlen(s);
		name_l = ft_strlen(f->name);
		def_l[0] = ft_strlen(FG_DEFAULT);
		def_l[1] = ft_strlen(BG_DEFAULT);
		ns = ft_strnew(s_l + name_l + def_l[0] + \
			((*(f->perms) == 'c' || *(f->perms) == 'b') ? (def_l[1]) : (0)));
		ft_strncpy(ns, s, s_l);
		ft_strncpy(ns + s_l, f->name, name_l);
		ft_strncpy(ns + s_l + name_l, FG_DEFAULT, def_l[0]);
		if (*(f->perms) == 'c' || *(f->perms) == 'b')
			ft_strncpy(ns + s_l + name_l + def_l[0], BG_DEFAULT, def_l[1]);
		free(f->name);
		free(s);
		f->name = ns;
	}
}
