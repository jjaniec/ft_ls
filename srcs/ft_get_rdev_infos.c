/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rdev_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:40:22 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/28 16:41:15 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Get major and minor number of a char/block device special file
*/

void	ft_get_rdev_infos(struct stat *f_stats, t_str_stats *f)
{
	f->rdev_min = minor(f_stats->st_rdev);
	f->rdev_maj = major(f_stats->st_rdev);
}
