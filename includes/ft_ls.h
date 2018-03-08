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

typedef int		t_bool;

# define TRUE	1
# define FALSE	0

typedef struct	s_opt
{
	t_bool	l;
	t_bool	r_caps;
	t_bool	a;
	t_bool	r;
	t_bool	t;
}				t_opt;

typedef struct	s_param
{
	char 			*s;
	struct s_param	*next;
}				t_param;

typedef struct	s_args
{
	struct s_opt	*opt;
	struct s_param	*prm;
}				t_args;

t_opt			*ft_parse_options(int ac, char **av);

t_param			*ft_parse_params(int ac, char **av, int rev);

t_param			*ft_create_param_elem(char *s);

void 			ft_handle_opt_err(char opt, char *pname);

void			ft_print_usage(char *pname);

void			ft_debug_ls_args(t_args arg);

t_param			*ft_append_elem(t_param *li, t_param *prm, int rev);

#endif
