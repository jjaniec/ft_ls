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

static void ft_toggle_opt(t_param *opts, char c)
{
    if (c == 'l')
        opts->l = TRUE;
    if (c == 'R')
        opts->R = TRUE;
    if (c == 'a')
        opts->a = TRUE;
    if (c == 'r')
        opts->r = TRUE;
    if (c == 't')
        opts->t = TRUE;
    ft_printf("{FG_GREEN}toggling %c opt\n", c);
}

static void ft_init_opt_struct(t_param *opts)
{
    opts->l = FALSE;
    opts->R = FALSE;
    opts->a = FALSE;
    opts->r = FALSE;
    opts->t = FALSE;
}

t_param     ft_parse_options(int ac, char **av)
{
    char        **ptr;
    t_param     opts;

    ptr = av;
    ft_init_opt_struct(&opts);
    --ac;
    while (ac != 0)
    {
        ptr = &ptr[1];
        if (**ptr == '-')
            ft_toggle_opt(&opts, *(*ptr + 1));
        --ac;
    }
    return (opts);
}