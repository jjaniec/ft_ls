/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:05 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/06 20:54:09 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_debug_prm(t_param *prm)
{
	t_param	*tmp;

	tmp = prm;
	ft_printf("\tparams:\n");
	if (!prm)
		ft_printf("\t\t(null)\n");
	else
		while (tmp)
		{
			ft_printf("\t\tprm: %s\n", tmp->s);
			tmp = tmp->next;
		}
}

static void	ft_debug_opt(t_opt *opts)
{
	ft_printf("\topts:\n");
	if (!opts)
		ft_printf("\t\t(null)\n");
	else
	{
		ft_printf("\t\topt l: %d\n", (*opts).l);
		ft_printf("\t\topt R: %d\n", (*opts).r_caps);
		ft_printf("\t\topt a: %d\n", (*opts).a);
		ft_printf("\t\topt r: %d\n", (*opts).r);
		ft_printf("\t\topt t: %d\n", (*opts).t);
	}
}

void		ft_debug_ls_args(t_args arg)
{
	ft_debug_opt(arg.opt);
	ft_debug_prm(arg.prm);
}