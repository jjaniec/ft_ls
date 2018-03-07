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

/*
** Init a t_args struct containing options in a t_opt struct and
** a pointer on a linked list containing all files/folder names of type t_param
*/

void		ft_init_args(int ac, char **av, t_args *args)
{
	t_opt	*opts;
	t_param	*params;

	opts = (ac > 1) ? (ft_parse_options(ac, av)) : (NULL);
	if (opts)
		params = (ac > 2) ? (ft_parse_params(ac, av)) : (NULL);
	else
		params = (ac > 1) ? (ft_parse_params(ac, av)) : (NULL);
	args->opt = opts;
	args->prm = params;
}


int		main(int ac, char **av)
{
	t_args	arg;

	ft_init_args(ac, av, &arg);
	ft_debug_ls_args(arg);
	return (0);
}
