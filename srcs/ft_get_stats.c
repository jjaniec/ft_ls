/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:54:04 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/20 15:17:37 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Store symlink target in filename
*/

void			ft_get_symlink_target(char *path, t_str_stats *f)
{
	char	*ns;
	ssize_t	len;
	size_t	name_len;
	char	*target;

	name_len = ft_strlen(f->name);
	target = ft_strnew(256);
	ns = ft_strnew(256 + name_len + 4);
	if ((len = readlink(path, target, 256)) != -1)
	{
		ft_strcpy(ns, f->name);
		ft_strcpy(ns + name_len, " -> ");
		ft_strcpy(ns + name_len + 4, target);
		free(f->name);
		f->name = ns;
		free(target);
	}
	else
	{
		free(target);
		free(ns);
	}
}

/*
** Read stats from passed char * and return a t_str_stats containing infos
** required for -l output of $arg file
*/

t_str_stats		*ft_get_stats_l_opt(\
		t_str_stats *f, struct stat *f_stats, t_opt *opts)
{
	f->slnks = f_stats->st_nlink;
	ft_fill_owners(f, f_stats, opts);
	f->size = f_stats->st_size;
	f->size_blocks = f_stats->st_blocks;
	return (f);
}

/*
** Read stats from passed char * and return a t_str_stats struct containing
** name and sets str_stats.folder to 1 if $s is a folder
*/

t_str_stats				*ft_get_stats(char *path, t_args *args, char *name)
{
	struct stat		arg_stats;
	t_str_stats		*f;

	f = ft_create_str_stats_elem(path);
	f->rcode = lstat(path, &arg_stats);
	if (f->rcode < 0)
		return (ft_free_str_stat_struct(f));
	f->name = ft_strdup(name);
	if (S_ISDIR(arg_stats.st_mode))
		f->folder = TRUE;
	ft_fill_perms(f, &arg_stats);
	ft_fill_ext_attr_acl(path, f);
	if (args->opt && args->opt->g_caps)
		ft_colorize_name(f);
	ft_fill_last_mod(f, &arg_stats, args);
	if (args->opt && args->opt->l)
		return (ft_get_stats_l_opt(f, &arg_stats, args->opt));
	return (f);
}
