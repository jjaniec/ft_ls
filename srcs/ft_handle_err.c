/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:17:57 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/17 22:15:27 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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
			PRINTF("ft_ls: cannot open directory '%s': Permission denied\n", path);
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