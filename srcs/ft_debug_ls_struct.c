/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ls_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:05 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/13 18:51:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** print content of a t_str_stats struct
*/

void	ft_debug_str_stats(char *name, t_str_stats *s, t_opt *opts)
{
	ft_printf("\t{FG_GREEN}t_str_stats of %s{FG_DEFAULT}:\n", name);
	if (!s)
		ft_printf("\t\t(null)\n");
	else
	{
		ft_printf("\t\tt_str_stats->name |%s|\n", s->name);
		ft_printf("\t\tt_str_stats->folder: |%d|\n", s->folder);
		ft_printf("\t\tt_str_stats->perms |%s|\n", s->perms);
		if (opts && opts->l)
		{
			ft_printf("\t\tt_str_stats->slnks |%d|\n", s->slnks);
			ft_printf("\t\tt_str_stats->ownr_uid |%u|\n", s->ownr_uid);
			ft_printf("\t\tt_str_stats->ownr_grp_uid |%u|\n", s->ownr_grp_uid);
			if (!opts->n)
			{
				ft_printf("\t\tt_str_stats->ownr |%s|\n", s->ownr);
				ft_printf("\t\tt_str_stats->ownr_grp |%s|\n", s->ownr_grp);
			}
			ft_printf("\t\tt_str_stats->size |%d|\n", s->size);
			ft_printf("\t\tt_str_stats->last_mod |%s|\n", s->last_mod);
			ft_printf("\t\tt_str_stats->rcode |%d|\n", s->rcode);
		}
	}
}

/*
** print content of a s_param linked list
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
** Print content of elements of a d_dir_content struct
*/

void	ft_debug_dir_content(t_dir_content *s, t_opt *opts)
{
	t_dir_entry	*tmp;

	tmp = s->elems;
	ft_printf("\nentries:\n");
	if (!s)
		ft_printf("\t\t(null)\n");
	else
	{
		ft_printf("\t\tc: %u\n\t\tblocks_total: %u\n", s->c, s->blocks_total);
		while (tmp)
		{
			ft_printf("\t\t\tentry: %s\n", tmp->s);
			ft_debug_str_stats(tmp->s, tmp->stats, opts);
			tmp = tmp->next;
		}
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
		ft_printf("\t\topt n: %d\n", (*opts).n);
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