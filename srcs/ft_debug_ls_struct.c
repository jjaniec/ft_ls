/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ls_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:05 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/21 19:14:25 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** print content of a t_str_stats struct
*/

void		ft_debug_str_stats(char *name, t_str_stats *s, t_opt *opts)
{
	PRINTF("\t{FG_GREEN}t_str_stats of %s{FG_DEFAULT}:\n", name);
	if (s)
	{
		PRINTF("\t\tt_str_stats->name |%s|\n", s->name);
		PRINTF("\t\tt_str_stats->folder: |%d|\n", s->folder);
		PRINTF("\t\tt_str_stats->perms |%s|\n", s->perms);
		PRINTF("\t\tt_str_stats->perms_attr_acl |%c|\n", s->perms_attr_acl);
		if (opts && opts->l)
		{
			PRINTF("\t\tt_str_stats->slnks |%d|\n", s->slnks);
			PRINTF("\t\tt_str_stats->ownr_uid |%u|\n", s->ownr_uid);
			PRINTF("\t\tt_str_stats->ownr_grp_uid |%u|\n", s->ownr_grp_uid);
			if (!opts->n)
			{
				PRINTF("\t\tt_str_stats->ownr |%s|\n", s->ownr);
				PRINTF("\t\tt_str_stats->ownr_grp |%s|\n", s->ownr_grp);
			}
			PRINTF("\t\tt_str_stats->size |%d|\n", s->size);
			PRINTF("\t\tt_str_stats->last_mod |%s|\n", s->last_mod);
			PRINTF("\t\tt_str_stats->last_modepoch |%lu|\n", s->last_mod_epoch);
			PRINTF("\t\tt_str_stats->size_blocks |%u|\n", s->size_blocks);
			PRINTF("\t\tt_str_stats->rcode |%d|\n", s->rcode);
		}
	}
}

/*
** print content of a s_param linked list
*/

void		ft_debug_prm(t_param *prm)
{
	t_param	*tmp;

	tmp = prm;
	PRINTF("\tparams:\n");
	if (!prm)
		PRINTF("\t\t(null)\n");
	else
		while (tmp && tmp->s)
		{
			PRINTF("\t\tprm: %s\n", tmp->s);
			tmp = tmp->next;
		}
}

/*
** Print content of elements of a d_dir_content struct
*/

void		ft_debug_dir_content(t_dir_content *s)
{
	t_dir_entry	*tmp;

	PRINTF("\nentries:\n");
	if (!s)
		PRINTF("\t\t(null)\n");
	else
	{
		tmp = s->elems;
		PRINTF("\t\tc: %u\n", s->c);
		while (tmp)
		{
			PRINTF("\t\t\tentry: %s\n", tmp->s);
			tmp = tmp->next;
		}
	}
}

/*
** Print content of a s_opt struct
*/

void		ft_debug_opt(t_opt *opts)
{
	PRINTF("\topts:\n");
	if (!opts)
		PRINTF("\t\t(null)\n");
	else
	{
		PRINTF("\t\topt l: %d\n", opts->l);
		PRINTF("\t\topt R: %d\n", opts->r_caps);
		PRINTF("\t\topt a: %d\n", opts->a);
		PRINTF("\t\topt r: %d\n", opts->r);
		PRINTF("\t\topt t: %d\n", opts->t);
		PRINTF("\t\topt n: %d\n", opts->n);
		PRINTF("\t\topt G: %d\n", opts->g_caps);
	}
}

/*
** print content of a s_args struct
*/

void		ft_debug_ls_args(t_args arg)
{
	ft_debug_opt(arg.opt);
	ft_debug_prm(arg.prm);
	PRINTF("\tr: %d\n", arg.r);
	PRINTF("\tprm_len: %d\n", arg.prm_len);
	PRINTF("\tcur_epoch: %lu\n", arg.cur_epoch);
}
