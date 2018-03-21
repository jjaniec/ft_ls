/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:00:45 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/21 19:07:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_strjoin_path(char *s1, char *s2)
{
	char	*r;
	size_t	l;

	l = ft_strlen(s1);
	r = malloc((l + ft_strlen(s2) + 2) * sizeof(char));
	ft_strcpy(r, s1);
	ft_strcpy(r + l + 1, s2);
	r[l] = '/';
	free(s1);
	free(s2);
	return (r);
}
