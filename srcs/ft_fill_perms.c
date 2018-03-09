/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_perms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:24:03 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 16:08:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_fill_perms(t_str_stats *f, struct stat *f_stats)
{
	char	*s;

	s = ft_strnew(10);
	*s = (f->folder) ? 'd' : '-';
	s[1] = ((f_stats->st_mode & S_IRUSR) ? 'r' : '-');
	s[2] = ((f_stats->st_mode & S_IWUSR) ? 'w' : '-');
	s[3] = ((f_stats->st_mode & S_IXUSR) ? 'x' : '-');
	s[4] = ((f_stats->st_mode & S_IRGRP) ? 'r' : '-');
	s[5] = ((f_stats->st_mode & S_IWGRP) ? 'w' : '-');
	s[6] = ((f_stats->st_mode & S_IXGRP) ? 'x' : '-');
	s[7] = ((f_stats->st_mode & S_IROTH) ? 'r' : '-');
	s[8] = ((f_stats->st_mode & S_IWOTH) ? 'w' : '-');
	s[9] = ((f_stats->st_mode & S_IXOTH) ? 'x' : '-');
	f->perms = s;
}