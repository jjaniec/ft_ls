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

static void		ft_toggle_opt(t_param *opts, char *str)
{
	while (*(++str))
	{
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

static void		ft_init_opt_struct(t_param *opts)
{
	opts->l = FALSE;
	opts->r_caps = FALSE;
	opts->a = FALSE;
	opts->r = FALSE;
	opts->t = FALSE;
}

t_param			ft_parse_options(int ac, char **av)
{
	char		**ptr;
	t_param		opts;

	ft_init_opt_struct(&opts);
	--ac;
	ptr = (ac >= 1) ? (&av[1]) : (NULL);
	while (ac > 0 && **ptr == '-')
	{
		if (**ptr == '-')
			ft_toggle_opt(&opts, (*ptr));
		--ac;
		ptr = (ac != 0) ? (&ptr[1]) : (NULL);
	}
	return (opts);
}
