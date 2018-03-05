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
	t_opt		opts;
	t_param		params;

	opts = ft_parse_options(ac, av);
	params = ft_parse_params(ac, av);
	return (ac);
}
