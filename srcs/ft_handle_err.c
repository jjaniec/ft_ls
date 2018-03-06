/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:17:57 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/06 18:17:58 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Handle option error and print usage
*/

void 			ft_handle_opt_err(char opt, char *pname)
{
	ft_printf("%s: illegal option -- %c\n", pname, opt);
	ft_print_usage(pname);
	exit(1);
}