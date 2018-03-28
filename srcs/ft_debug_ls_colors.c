/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ls_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:09:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/28 16:41:28 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_debug_ls_colors(t_ls_colors *cl)
{
	PRINTF("\tcolors: \n");
	if (!cl)
		PRINTF("\t\tDefault\n");
	else
	{
		PRINTF("\t\t%scl->di\n", cl->di);
		PRINTF("\t\t%scl->ln\n", cl->ln);
		PRINTF("\t\t%scl->so\n", cl->so);
		PRINTF("\t\t%scl->pi\n", cl->pi);
		PRINTF("\t\t%scl->ex\n", cl->ex);
		PRINTF("\t\t%scl->bd\n", cl->bd);
		PRINTF("\t\t%scl->cd\n", cl->cd);
		PRINTF("\t\t%scl->su\n", cl->su);
		PRINTF("\t\t%scl->sg\n", cl->sg);
		PRINTF("\t\t%scl->tw\n", cl->tw);
		PRINTF("\t\t%scl->ow\n%s", cl->ow, COLOR_RESET);
	}
}
