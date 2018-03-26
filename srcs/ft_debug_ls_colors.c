/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ls_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:09:10 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/26 21:13:19 by jjaniec          ###   ########.fr       */
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
		PRINTF("\t\tcl->di: %s\n", cl->di);
		PRINTF("\t\tcl->ln: %s\n", cl->ln);
		PRINTF("\t\tcl->so: %s\n", cl->so);
		PRINTF("\t\tcl->pi: %s\n", cl->pi);
		PRINTF("\t\tcl->ex: %s\n", cl->ex);
		PRINTF("\t\tcl->bd: %s\n", cl->bd);
		PRINTF("\t\tcl->cd: %s\n", cl->cd);
		PRINTF("\t\tcl->su: %s\n", cl->su);
		PRINTF("\t\tcl->sg: %s\n", cl->sg);
		PRINTF("\t\tcl->tw: %s\n", cl->tw);
		PRINTF("\t\tcl->ow: %s\n", cl->ow);
	}
}