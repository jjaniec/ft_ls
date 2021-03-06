/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:17:57 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/04 14:04:22 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_handle_not_found_err(char *s)
{
	if (errno == EBADF)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": Bad file descriptor\n", 2);
	}
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		if (*__OS__ == 'L')
			ft_putstr_fd("cannot access '", 2);
		ft_putstr_fd(s, 2);
		if (*__OS__ == 'L')
			ft_putstr_fd("': No such file or directory\n", 2);
		else
			ft_putstr_fd(": No such file or directory\n", 2);
	}
}

/*
** Checks why ft_ls can't read direcory $path, print
** associated error message and modify return value
*/

static void	ft_print_err_head(char *path, t_args *args)
{
	if (!(args->cur_elem == 0 && ft_strcmp(path, args->prm->s) == 0))
		PRINTF("\n");
	if (args->prm_len > 1 || (args->opt && args->opt->r_caps && args->prm && args->prm->stats && args->prm->stats->perms[3] != '-'))
		PRINTF("%s:\n", path);
}

void		*ft_handle_dir_err(char *path, t_args *args, int *dir_err)
{
	struct stat		dir_stats;

	if (!(lstat(path, &dir_stats)))
		if (S_ISDIR(dir_stats.st_mode))
		{
			if (*__OS__ == 'L')
				ft_putstr_fd("ft_ls: cannot open directory '", 2);
			else
			{
				ft_print_err_head(path, args);
				ft_putstr_fd("ft_ls: ", 2);
			}
			ft_putstr_fd(path, 2);
			if (*__OS__ == 'L')
				ft_putstr_fd("'", 2);
			ft_putstr_fd(": Permission denied\n", 2);
			if (args->r != 2)
				args->r = 1;
			if (args->cur_elem == 0 && args->cur_loop == 0 && args->prm && \
				args->prm->next && args->prm->stats && \
				args->prm->next->stats->perms[3] != '-')
				PRINTF("\n");
		}
	*dir_err = 1;
	return (NULL);
}

/*
** Handle option error and print usage
*/

void		ft_handle_opt_err(char opt, char *pname)
{
	ft_putstr_fd(pname, 2);
	if (*__OS__ == 'L')
		ft_putstr_fd(": invalid option -- ", 2);
	else
		ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putchar_fd('\n', 2);
	ft_print_usage(pname);
	exit(2);
}
