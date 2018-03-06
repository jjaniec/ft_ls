/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:41 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/05 21:53:43 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Parse options contained in $str
**
** Parsed options:
** l : List in long format.
** R : Recursively list subdirectories encountered.
** a : Include directory entries whose names begin with a dot (.).
** r : Reverse the order of the sort to get reverse lexicographical order
**     or the oldest entries first.
** t : Sort by time modified (most recently modified first)
*/

static void		ft_toggle_opt(t_opt *opts, char *str, char *pname)
{
	while (*(++str))
	{
		if (*str != 'l' && *str != 'R' && \
			*str != 'a' && *str != 'r' && \
			*str != 't')
			ft_handle_opt_err(*str, pname);
		if (*str == 'l')
			opts->l = TRUE;
		if (*str == 'R')
			opts->r_caps = TRUE;
		if (*str == 'a')
			opts->a = TRUE;
		if (*str == 'r')
			opts->r = TRUE;
		if (*str == 't')
			opts->t = TRUE;
		ft_printf("{FG_GREEN}toggling [%c] opt\n", *str);
	}
}

/*
** Takes a t_param * and set all it's elements to FALSE
*/

static void		ft_init_opt_struct(t_opt **opts)
{
	(*opts) = malloc(sizeof(t_opt));
	(*opts)->l = FALSE;
	(*opts)->r_caps = FALSE;
	(*opts)->a = FALSE;
	(*opts)->r = FALSE;
	(*opts)->t = FALSE;
}

/*
** Cycle through cli arguments while *(av[x]) != '-'
** and store found paramaters in the opts struct
*/

t_opt			*ft_parse_options(int ac, char **av)
{
	char		**ptr;
	t_opt		*opts;

	opts = NULL;
	ft_init_opt_struct(&opts);
	--ac;
	ptr = &av[1];
	while (ac-- > 0 && **ptr == '-' && !((*ptr)[0] == '-' && (*ptr)[1] == '-'))
	{
		ft_printf("{FG_RED}opt : %s\n", *ptr);
		if (**ptr == '-')
			ft_toggle_opt(opts, (*ptr), av[0]);
		ft_printf("{FG_RED}opt : %s\n", *ptr);
		ptr = (ac != 0) ? (&ptr[1]) : (NULL);
	}
	return (opts);
}
