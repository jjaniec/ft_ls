/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:25:55 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/06 19:25:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prints usage of the program
*/

void	ft_print_usage(char *pname)
{
	ft_printf("usage: %s [lRart] [file ...]\n", pname);
}