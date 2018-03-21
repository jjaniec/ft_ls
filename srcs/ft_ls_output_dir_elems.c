/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_output_dir_elems.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:59:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/21 15:36:22 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_output_dir_elems(t_dir_content *dc, int *dir_err, t_args *args, char *s)
{
	t_dir_entry		*ptr;

	(terpri);
	ptr = (dc) ? (dc->elems) : (NULL);
	if (*dir_err == 0)
	{
		if (s && ((args->opt && args->opt->r_caps) || (args->prm_len > 1)))
			PRINTF("%s:\n", s);
		if (dc && args->opt && (args->opt->l))
			PRINTF("total %d\n", dc->blocks_total);
	}
	while (ptr)
	{
		if (ptr->stats)
			ft_ls_output_entry(ptr->stats, args->opt);
		ptr = ptr->next;
	}
}