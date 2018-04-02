/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_output_dir_elems.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:59:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/01 00:13:01 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Print total and folder name if needed and
** output dir elements infos with ft_ls_output_entry
*/

static void		ft_print_head(char *s, t_args *args, t_dir_content *dc)
{
	if ((args->prm_len > 1) || \
		(dc && \
		(ft_strcmp(s, dc->s) != 0 || \
		(args->prm_len == 1 && args->opt && args->opt->r_caps && \
			ft_strcmp(args->prm->s, dc->s) != 0) || \
		(args->prm_len < 1 && args->opt && args->opt->r_caps && \
			!(s[0] == '.' && !s[1])))))
		PRINTF("%s:\n", s);
	if (args->opt && args->opt->l && dc->elems && dc->elems->stats)
		PRINTF("total %d\n", (*__OS__ == 'L') ? \
			(dc->blocks_total / 2) : (dc->blocks_total));
}

void			ft_ls_output_dir_elems(t_dir_content *dc, int *dir_err, \
			t_args *args, char *s)
{
	t_dir_entry		*ptr;

	if (args->file_cli_args)
		PRINTF("\n");
	else
		args->file_cli_args = 1;
	ptr = (dc) ? (dc->elems) : (NULL);
	if (*dir_err == 0)
		ft_print_head(s, args, dc);
	while (ptr)
	{
		if (ptr->stats)
			ft_ls_output_entry(ptr->stats, args->opt);
		ptr = ptr->next;
	}
}
