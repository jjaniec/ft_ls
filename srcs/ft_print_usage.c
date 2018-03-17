/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:25:55 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/16 15:16:41 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prints usage of the program
*/

void	ft_print_usage(char *pname)
{
	PRINTF("usage: %s [lRart] [file ...]\n", pname);
}