/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/05 21:53:14 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	t_opt		*opts;
	t_param		*params;

	opts = (ac > 1) ? (ft_parse_options(ac, av)) : (NULL);
	params = (ac > 1) ? (ft_parse_params(ac, av)) : (NULL);
	return (0);
}
