/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_str_alphacmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:45:51 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/28 16:39:42 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** These functions compares strings without minding caps and by skipping '.'
** like the order of the readl linux ls, but,
** as the real ls uses strcoll, I tried to mimic it as much
** as possible but it can't be 100% exactly the same order
** depending on $LC_COLLATE
*/

int		ft_str_alphacmp(char *s1, char *s2)
{
	char	c;
	char	c2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		c = s1[i];
		c2 = s2[j];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		if (c2 >= 'A' && c2 <= 'Z')
			c2 += 32;
		if (c != c2)
			break ;
		i++;
		j++;
	}
	if (c == c2 && !c)
		return (0);
	else if (c == c2 && ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	return ((unsigned int)c - (unsigned int)c2);
}

int		ft_ls_str_alphacmp(char *s1, char *s2)
{
	int		offset_s1;
	int		offset_s2;
	int		r;

	r = 0;
	if (ft_strcmp(s2, ".") == 0)
		return (1);
	else if (s1[0] == '.' && ((s1[1] == '.' && !s1[2]) || !s1[1]))
		return (-1);
	offset_s1 = 0;
	offset_s2 = 0;
	while (s1[offset_s1] == '.')
		offset_s1++;
	if (!(s1[offset_s1]))
		return (1);
	while (s2[offset_s2] == '.')
		offset_s2++;
	r = ft_str_alphacmp(s1 + offset_s1, s2 + offset_s2);
	if (offset_s1 < offset_s2 && r == 0 && \
		ft_strlen(s1 + offset_s1) == ft_strlen(s2 + offset_s2))
		return (-1);
	return (r);
}
