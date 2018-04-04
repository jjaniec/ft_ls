/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 23:44:49 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/26 17:30:24 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Creates linked list's first argument and init return value of ft_parse_params
*/

static void			*ft_init_params_list(\
						t_param **initptr, char *s, t_args *args, int *r)
{
	t_param		*t;

	t = ft_create_param_elem(s, args, r);
	*initptr = t;
	return (t);
}

/*
** Parse cli parameters like file or folder names
*/

t_param				*ft_parse_params(int ac, char **av, t_args *args)
{
	t_param		*li;
	t_param		*tmp;
	int			i;

	i = 1;
	li = NULL;
	while (i < ac && av[i][0] == '-' && !(ft_strcmp(av[i], "--") == 0) && \
			ft_is_option(&av[i][1]))
		i++;
	if (i < ac && ft_strcmp(av[i], "--") == 0)
		i++;
	while (i < ac)
	{
		if (li)
		{
			tmp = ft_create_param_elem(av[i], args, &(args->r));
			li = (tmp) ? (ft_append_elem(li, tmp, args->opt)) : (li);
		}
		else
			ft_init_params_list(&li, av[i], args, &(args->r));
		i++;
		args->prm_len++;
	}
	return (li);
}
