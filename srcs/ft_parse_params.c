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

static void			*ft_init_params_list(t_param *initptr, t_param *li, char *s)
{
	t_param		*t;

	t = ft_create_param_elem(s);
	li = t;
	initptr = t;
	return (t);
}

/*
** Skip param in ptr
*/

static void			ft_skip_param(int *ac, char ***ptr)
{
	*ptr = &ptr[0][1];
	*ac -= 1;
}

/*
** Parse cli parameters like file or folder names
*/

t_param				*ft_parse_params(int ac, char **av)
{
	t_param		*params;
	t_param		*ret;
	char 		**ptr;

	--ac;
	ptr = (ac >= 1) ? (&av[1]) : (NULL);
	ret = NULL;
	while (ac-- > 0 && **ptr == '-' && !((*ptr)[0] == '-' && (*ptr)[1] == '-'))
		ptr = &ptr[1];
	if ((strcmp(*ptr, "--") == 0))
		ft_skip_param(&ac, &ptr);
	ft_printf("{FG_MAGENTA}begin params : %s\n", *ptr);
	while (ac-- > 0)
	{
		params = (!ret) ? \
			(ft_init_params_list(ret, params, *ptr)) : (ft_create_param_elem(*ptr));
		ft_printf("{FG_GREEN}Param : %s\n", params->s);
		params = params->next;
		ptr = &ptr[1];
	}
	return (ret);
}