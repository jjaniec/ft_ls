/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:41 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/26 17:47:34 by jjaniec          ###   ########.fr       */
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
		if (!ft_is_option(str))
			ft_handle_opt_err(*str, pname);
		if (ft_strcmp("-linux-sort", str) == 0)
		{
			opts->linux_sort = TRUE;
			break;
		}
		if (*str == 'l')
			opts->l = TRUE;
		if (*str == 'R')
			opts->r_caps = TRUE;
		if (*str == 'a')
			opts->a = TRUE;
		if (*str == 'A')
			opts->a_caps = TRUE;
		if (*str == 'r')
			opts->r = TRUE;
		if (*str == 't')
			opts->t = TRUE;
		if (*str == 'n')
		{
			opts->n = TRUE;
			opts->l = TRUE;
		}
		if (*str == 'G' || ft_strcmp("-color", str) == 0)
		{
			opts->g_caps = TRUE;
			if (*str != 'G')
				break;
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
	(*opts)->a_caps = FALSE;
	(*opts)->r = FALSE;
	(*opts)->t = FALSE;
	(*opts)->n = FALSE;
	(*opts)->g_caps = FALSE;
	(*opts)->linux_sort = FALSE;
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
	while (ac-- > 0 && **ptr == '-' && !(ft_strcmp(*ptr, "--") == 0))
	{
		if (**ptr == '-')
			ft_toggle_opt(opts, (*ptr), av[0]);
		ptr = (ac != 0) ? (&ptr[1]) : (NULL);
	}
	return (opts);
}
