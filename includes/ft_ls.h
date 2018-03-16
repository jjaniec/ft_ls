/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:25 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/16 15:53:54 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <ft_printf.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <time.h>

# define DIR_COLOR FG_BLUE
# define EXEC_COLOR FG_RED
# define SYMLINK_COLOR FG_MAGENTA

# define PRINTF ft_printf

typedef int			t_bool;

# define TRUE 1
# define FALSE 0

# define terpri		ft_putchar('\n')

/*
** Struct to store options, toggle booleans if option is specified
*/

typedef struct	s_opt
{
	t_bool		l;
	t_bool		r_caps;
	t_bool		a;
	t_bool		r;
	t_bool		t;
	t_bool		n;
	t_bool		g_caps;
}				t_opt;

/*
** Struct to store converted content of
** the stat(3) and lstats(3) functions
*/

typedef struct		s_str_stats
{
	char			*name;
	t_bool			folder;
	char			*perms;
	int				slnks;
	char			*ownr;
	unsigned int	ownr_uid;
	char			*ownr_grp;
	unsigned int	ownr_grp_uid;
	int				size;
	char			*last_mod;
	unsigned int	size_blocks;
	int				rcode;
}					t_str_stats;

/*
** Struct to store cli parameters in a linked list
*/

typedef struct		s_param
{
	char			*s;
	t_str_stats		*stats;
	struct s_param	*next;
}					t_param;

/*
** Struct to wrap options and cli parameters linked list
*/

typedef struct		s_args
{
	struct s_opt	*opt;
	struct s_param	*prm;
	int				r;
}					t_args;

/*
** Struct to store name of each element and it's stats
** found in a directory, by a linked list
*/

typedef struct		s_dir_entry
{
	char					*s;
	t_str_stats				*stats;
	struct s_dir_entry		*next;
}					t_dir_entry;

/*
** Struct with $c to store number of elements in the $elems linked list
*/

typedef struct		s_dir_content
{
	unsigned int	c;
	t_dir_entry		*elems;

}					t_dir_content;

t_opt			*ft_parse_options(int ac, char **av);

t_param			*ft_parse_params(int ac, char **av, t_args *args);

t_param			*ft_create_param_elem(char *s, t_opt *opts, int *r);

t_str_stats		*ft_create_str_stats_elem(char *s);

void 			ft_handle_opt_err(char opt, char *pname);

void			ft_print_usage(char *pname);

void			ft_debug_ls_args(t_args arg);

t_param			*ft_append_elem(t_param *li, t_param *prm, int rev);

t_str_stats		*ft_get_stats(char *str, t_opt *opt, char *name);

t_str_stats		*ft_get_stats_l_opt(t_str_stats *f, struct stat *f_stats, \
					t_opt *opts);

void			ft_ls(t_args args);

void			ft_debug_str_stats(char *name, t_str_stats *s, t_opt *opts);

void			ft_debug_prm(t_param *prm);

void			ft_debug_opt(t_opt *opts);

void			*ft_free_str_stat_struct(t_str_stats *t_s);

void			ft_fill_perms(t_str_stats *f, struct stat *f_stats);

void			ft_fill_owners(t_str_stats *f, struct stat *f_stats, \
					t_opt *opts);

void			ft_fill_last_mod(t_str_stats *f, struct stat *f_stats);

void			ft_colorize_name(t_str_stats *f);

t_dir_content	*ft_create_folder_elems_ll(char *path, int rev, t_opt *opts, \
					int *total_blk);

char			*ft_strjoin_path(char *s1, char *s2);

t_dir_entry		*ft_append_direntry(t_dir_entry *li, t_dir_entry *new, int rev);

t_dir_entry		*ft_create_dir_entry_elem(char *s, char *path, t_opt *opts, \
					int *total_blk);

t_dir_content	*ft_create_dir_content_s(void);

t_dir_entry		*ft_append_direntry(t_dir_entry *li, t_dir_entry *new, int rev);

void			ft_debug_dir_content(t_dir_content *s);

void			ft_ls_output_entry(t_str_stats *de, t_opt *opts);

int				ft_can_recurse(t_dir_entry *s);

int				ft_is_option(char *str);

void			ft_get_symlink_target(char *path, t_str_stats *f);

#endif
