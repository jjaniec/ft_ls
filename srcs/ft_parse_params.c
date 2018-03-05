/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 23:44:49 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/05 23:44:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ft_ls.h>

/*
** Parse cli parameters like file or folder names
*/

t_param		*ft_parse_params(int ac, char **av)
{
	t_param		*params;
	char 		**av_ptr;

	av_ptr = av;
	params = NULL;
	while (ac > 0 && **av == '-')
	{
		av_ptr = &av_ptr[1];
		--ac;
	}
	//params = malloc(sizeof(t_param));
	return (NULL);
}