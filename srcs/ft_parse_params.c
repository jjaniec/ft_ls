/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 23:44:49 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/05 23:44:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ft_ls.h>

/*
** Creates t_param elem with content passed as parameter and set next to null
*/

static t_param		*ft_create_param_elem(char *s)
{
	t_param		*p;

	p = malloc(sizeof(t_param));
	p->s = s;
	p->next = NULL;
	return (p);
}

/*
** Creates linked list's first argument and init return value of ft_parse_params
*/

static void			*ft_init_params_list(t_param **initptr, t_param *li, char *s)
{
	t_param		*t;

	t = ft_create_param_elem(s);
	li = t;
	*initptr = t;
	return (t);
}

/*
** Skip param in ptr
*/

static void			ft_skip_param(int *ac, char ***ptr)
{
	if (ac > 0)
		*ptr = &ptr[0][1];
	*ac -= 1;
}

/*
** Parse cli parameters like file or folder names
*/

t_param				*ft_parse_params(int ac, char **av, int rev)
{
	t_param		*params;
	t_param		*ret;
	char 		**ptr;

	if (rev)
		return (ft_parse_params_rev(ac, av));
	--ac;
	ptr = &av[1];
	ret = NULL;
	while (ac-- > 0 && **ptr == '-' && !((*ptr)[0] == '-' && (*ptr)[1] == '-'))
		ptr = &ptr[1];
	if ((strcmp(*ptr, "--") == 0))
		ft_skip_param(&ac, &ptr);
	while (ac-- > -1)
	{
		if (ret)
		{
			params->next = ft_create_param_elem(*ptr);
			params = params->next;
		}
		else
			params = ft_init_params_list(&ret, params, *ptr);
		ptr = &ptr[1];
	}
	return (ret);
}

/*
** Parse cli parameters like file or folder names in reverse for -r option
*/

t_param				*ft_parse_params_rev(int ac, char **av)
{
	t_param		*ret;
	t_param		*params;
	int			i;
	i = 0;

	ret = NULL;
	while (++i < ac && (*(av[i]) == '-'))
		;
	while (ac > i)
	{
		if (ret)
		{
			params->next = ft_create_param_elem(av[ac]);
			params = params->next;
		}
		else
			params = ft_init_params_list(&ret, params, av[ac]);
		ac--;
	}
	return (ret);
}