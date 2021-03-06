/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:35:56 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/04 14:45:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Search for specified color in LS_COLOR environnement variable data
*/

static char		*ft_parse_color(char *type, char *env_data)
{
	char	*p;
	int		i;
	char	*tmp;

	i = 0;
	p = ft_strstr(env_data, type);
	if (p && p[1] && p[2] && p[3])
	{
		while (p[i] && p[i] != ':')
			i++;
		if (i == 0)
			return (NULL);
		tmp = ft_strsub(p, 3, i - 3);
		p = ft_strjoin("\e[", tmp);
		free(tmp);
		tmp = ft_strjoin(p, "m");
		free(p);
		p = tmp;
	}
	return (p);
}

/*
** Store color of each type of file in a t_ls_colors struct
*/

void			ft_init_colors(t_args *args)
{
	char		*s;
	t_ls_colors	*e;

	s = NULL;
	args->cl = NULL;
	if (args->opt && args->opt->g_caps)
		s = getenv("FT_LS_COLORS");
	if (s)
	{
		e = malloc(sizeof(t_ls_colors));
		e->di = ft_parse_color("di=", s);
		e->ln = ft_parse_color("ln=", s);
		e->so = ft_parse_color("so=", s);
		e->pi = ft_parse_color("pi=", s);
		e->ex = ft_parse_color("ex=", s);
		e->bd = ft_parse_color("bd=", s);
		e->cd = ft_parse_color("cd=", s);
		e->su = ft_parse_color("su=", s);
		e->sg = ft_parse_color("sg=", s);
		e->tw = ft_parse_color("tw=", s);
		e->ow = ft_parse_color("ow=", s);
		args->cl = e;
	}
}
