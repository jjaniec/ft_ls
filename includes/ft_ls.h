/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:53:25 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/25 18:05:24 by jjaniec          ###   ########.fr       */
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
# include <sys/xattr.h>

# ifdef __linux__
#  define __OS__ "Linux"
# endif
# ifdef __APPLE__
#  define __OS__ "Darwin"
#  include <sys/acl.h>
# endif
# ifndef __OS__
#  define __OS__ "?"
# endif

# define DIR_COLOR FG_BLUE
# define EXEC_COLOR FG_RED
# define SYMLINK_COLOR FG_MAGENTA
# define SPECIAL_COLOR FG_BLUE
# define FIFO_COLOR FG_YELLOW
# define BLOCK_SPE_BG_COLOR BG_MAGENTA
# define CHAR_SPE_BG_COLOR BG_YELLOW
# define PRINTF printf

typedef int			t_bool;

# define TRUE 1
# define FALSE 0

/*
** Struct to store options, toggle booleans if option is specified
*/

typedef struct		s_opt
{
	t_bool			l;
	t_bool			r_caps;
	t_bool			a;
	t_bool			r;
	t_bool			t;
	t_bool			n;
	t_bool			g_caps;
}					t_opt;

/*
** Struct to store converted content of
** the stat(3) and lstats(3) functions
*/

typedef struct		s_str_stats
{
	char			*name;
	t_bool			folder;
	char			*perms;
	char			perms_attr_acl;
	int				slnks;
	char			*ownr;
	unsigned int	ownr_uid;
	char			*ownr_grp;
	unsigned int	ownr_grp_uid;
	int				size;
	char			*last_mod;
	unsigned long	last_mod_epoch;
	unsigned int	size_blocks;
	unsigned int	rdev_min;
	unsigned int	rdev_maj;
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
	int				prm_len;
	int				r;
	unsigned long	cur_epoch;
	int				file_cli_args;
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
	int				blocks_total;
	t_dir_entry		*elems;

}					t_dir_content;

t_opt				*ft_parse_options(int ac, char **av);

t_param				*ft_parse_params(int ac, char **av, t_args *args);

t_param				*ft_create_param_elem(char *s, t_args *args, int *r);

t_str_stats			*ft_create_str_stats_elem(char *s);

void				ft_handle_opt_err(char opt, char *pname);

void				ft_print_usage(char *pname);

void				ft_debug_ls_args(t_args arg);

t_param				*ft_append_elem(t_param *li, t_param *prm, t_opt *opts);

t_str_stats			*ft_get_stats(char *str, t_args *args, char *name);

t_str_stats			*ft_get_stats_l_opt(t_str_stats *f, struct stat *f_stats, \
						t_opt *opts);

void				ft_ls(t_args args);

void				ft_debug_str_stats(char *name, t_str_stats *s, t_opt *opts);

void				ft_debug_prm(t_param *prm);

void				ft_debug_opt(t_opt *opts);

void				*ft_free_str_stat_struct(t_str_stats *t_s);

void				ft_fill_perms(t_str_stats *f, struct stat *f_stats);

void				ft_fill_owners(t_str_stats *f, struct stat *f_stats, \
						t_opt *opts);

void				ft_fill_last_mod(t_str_stats *f, struct stat *f_stats, \
						t_args *args);

void				ft_colorize_name(t_str_stats *f);

t_dir_content		*ft_create_folder_elems_ll(char *path, int *dir_err, \
						t_args *args);

char				*ft_strjoin_path(char *s1, char *s2);

t_dir_entry			*ft_append_direntry(t_dir_entry *li, t_dir_entry *new, \
						t_opt *opts);

t_dir_entry			*ft_create_dir_entry_elem(char *s, char *path, \
						t_args *args, int *total_blk);

t_dir_content		*ft_create_dir_content_s(void);

void				ft_debug_dir_content(t_dir_content *s);

void				ft_ls_output_entry(t_str_stats *de, t_opt *opts);

int					ft_can_recurse(t_dir_entry *s);

int					ft_is_option(char *str);

void				ft_get_symlink_target(char *path, t_str_stats *f);

void				ft_free_dir_entry(t_dir_entry *de);

void				ft_free_param_elem(t_param *e);

void				ft_free_ptr(void *ptr);

void				*ft_handle_dir_err(char *path, t_args *args, int *dir_err);

void				ft_ls_output_dir_elems(t_dir_content *dc, int *dir_err, \
						t_args *args, char *s);

void				ft_handle_not_found_err(char *s);

void				ft_ls_foreach_in_dir(char *s, t_args *args);

void				ft_get_rdev_infos(struct stat *f_stats, t_str_stats *f);


# ifdef __linux__
#  include <sys/sysmacros.h>
#  define ft_fill_ext_attr_acl(path, f);
# endif
# ifdef __APPLE__
#  include <sys/acl.h>
void				ft_fill_ext_attr_acl(char *path, t_str_stats *f_stats);
# endif

#endif
