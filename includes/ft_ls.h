/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:25 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/05 21:53:30 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <ft_printf.h>

typedef int bool;

# define TRUE 1
# define FALSE 0

typedef struct  s_param
{
    bool    l;
    bool    R;
    bool    a;
    bool    r;
    bool    t;
}               t_param;

t_param ft_parse_options(int ac, char **av);

#endif
    