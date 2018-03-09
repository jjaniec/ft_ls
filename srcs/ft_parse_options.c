/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:41 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/09 17:03:45 by jjaniec          ###   ########.fr       */
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
** n : Display user and group IDs numerically,
**     rather than converting to a user or group name in a long (-l) output.
*/

static void		ft_toggle_opt(t_opt *opts, char *str, char *pname)
{
	while (*(++str))
	{
		if (*str != 'l' && *str != 'R' && \
			*str != 'a' && *str != 'r' && \
			*str != 't' && *str != 'n')
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
		if (*str == 'n')
		{
			opts->n = TRUE;
			opts->l = TRUE;
		}
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
	(*opts)->n = FALSE;
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
		if (**ptr == '-')
			ft_toggle_opt(opts, (*ptr), av[0]);
		ptr = (ac != 0) ? (&ptr[1]) : (NULL);
	}
	if (opts && !opts->l && !opts->r_caps && !opts->a && !opts->r && !opts->t)
	{
		free(opts);
		opts = NULL;
	}
	return (opts);
}
