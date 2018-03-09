/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:34:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 18:47:48 by jjaniec          ###   ########.fr       */
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
	if (f->folder || f->perms[3] == 'x')
	{
		if (f->folder)
			f->name = ft_strjoin(DIR_COLOR, f->name);
		else
			f->name = ft_strjoin(EXEC_COLOR, f->name);
		f->name = ft_strjoin(f->name, FG_WHITE);
	}

}