/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:25:55 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/25 18:56:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prints usage of the program
*/

void	ft_print_usage(char *pname)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(pname, 2);
	ft_putstr_fd(" [lRaArtnG] [file ...]\n", 2);
}
