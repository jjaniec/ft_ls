/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_last_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:13:17 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 18:30:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Takes last modification information and format it like the ls -l option does
** char			*ft_strsub_free(char *s, unsigned int start, size_t len);
*/

void		ft_fill_last_mod(t_str_stats *f, struct stat *f_stats)
{
	char	*s;

	s = ctime(&(*f_stats).st_mtime);
	f->last_mod = ft_strsub(s + 4, 0, ft_strlen(s + 4) - 9);
}