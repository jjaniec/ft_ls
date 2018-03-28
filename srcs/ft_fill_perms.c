/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_perms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:24:03 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/28 17:09:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Apply mask on each permission and return a string containing
** characters for each permission
** ls -l like
*/

void	ft_fill_perms(t_str_stats *f, struct stat *f_stats)
{
	f->perms[0] = (f->folder) ? ('d') : ('-');
	f->perms[0] = (S_ISLNK(f_stats->st_mode)) ? ('l') : (*(f->perms));
	f->perms[0] = (S_ISCHR(f_stats->st_mode)) ? ('c') : (*(f->perms));
	f->perms[0] = (S_ISBLK(f_stats->st_mode)) ? ('b') : (*(f->perms));
	f->perms[0] = (S_ISFIFO(f_stats->st_mode)) ? ('p') : (*(f->perms));
	f->perms[0] = (S_ISSOCK(f_stats->st_mode)) ? ('s') : (*(f->perms));
	f->perms[1] = ((f_stats->st_mode & S_IRUSR) ? 'r' : '-');
	f->perms[2] = ((f_stats->st_mode & S_IWUSR) ? 'w' : '-');
	if (f_stats->st_mode & S_ISUID)
		f->perms[3] = ((f_stats->st_mode & S_IXUSR) ? 's' : 'S');
	else
		f->perms[3] = ((f_stats->st_mode & S_IXUSR) ? 'x' : '-');
	f->perms[4] = ((f_stats->st_mode & S_IRGRP) ? 'r' : '-');
	f->perms[5] = ((f_stats->st_mode & S_IWGRP) ? 'w' : '-');
	if (f_stats->st_mode & S_ISGID)
		f->perms[6] = ((f_stats->st_mode & S_IXGRP) ? 's' : 'S');
	else
		f->perms[6] = ((f_stats->st_mode & S_IXGRP) ? 'x' : '-');
	f->perms[7] = ((f_stats->st_mode & S_IROTH) ? 'r' : '-');
	f->perms[8] = ((f_stats->st_mode & S_IWOTH) ? 'w' : '-');
	if (f_stats->st_mode & S_ISVTX)
		f->perms[9] = (f_stats->st_mode & S_IXOTH) ? ('t') : ('T');
	else
		f->perms[9] = (f_stats->st_mode & S_IXOTH) ? ('x') : ('-');
	f->perms[10] = '\0';
}
