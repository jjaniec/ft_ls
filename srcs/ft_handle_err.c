/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:17:57 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/21 19:31:03 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_handle_not_found_err(char *s)
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

/*
** Checks why ft_ls can't read direcory $path, print
** associated error message and modify return value
*/

void		*ft_handle_dir_err(char *path, t_args *args, int *dir_err)
{
	struct stat		dir_stats;

	if (!(lstat(path, &dir_stats)))
		if (S_ISDIR(dir_stats.st_mode))
		{
			if (*__OS__ == 'L')
				ft_putstr_fd("cannot open directory '", 2);
			else
			{
				PRINTF("\n%s:\n", path);
				ft_putstr_fd("ft_ls: ", 2);
			}
			ft_putstr_fd(path, 2);
			if (*__OS__ == 'L')
				ft_putstr_fd("': Permission denied\n", 2);
			else
				ft_putstr_fd(": Permission denied\n", 2);
			args->r = 1;
		}
	*dir_err = 1;
	return (NULL);
}

/*
** Handle option error and print usage
*/

void		ft_handle_opt_err(char opt, char *pname)
{
	PRINTF("%s: illegal option -- %c\n", pname, opt);
	ft_print_usage(pname);
	exit(1);
}
