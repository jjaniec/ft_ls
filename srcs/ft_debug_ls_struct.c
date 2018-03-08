/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ls_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:05 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/08 21:02:02 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** print content of a t_str_stats struct
*/

void	ft_debug_str_stats(char *name, t_str_stats *s)
{
	ft_printf("\t{FG_GREEN}t_str_stats of %s{FG_DEFAULT}:\n", name);
	if (!s)
		ft_printf("\t\t(null)\n");
	else
	{
		ft_printf("\t\tt_str_stats->name %s:\n", s->name);
		ft_printf("\t\tt_str_stats->folder %d:\n", s->folder);

		ft_printf("\t\tt_str_stats->rcode %d:\n", s->rcode);
	}
}

/*
** print content of a s_param struct
*/

void	ft_debug_prm(t_param *prm)
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

/*
** print content of a s_opt struct
*/

void	ft_debug_opt(t_opt *opts)
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

/*
** print content of a s_args struct
*/

void		ft_debug_ls_args(t_args arg)
{
	ft_debug_opt(arg.opt);
	ft_debug_prm(arg.prm);
}