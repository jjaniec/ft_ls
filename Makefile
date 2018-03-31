# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 21:53:56 by jjaniec           #+#    #+#              #
#    Updated: 2018/03/31 17:50:58 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

UNAME_S := $(shell uname -s)

SRC_NAME = 	ft_append_elem.c \
			ft_colorize_name.c \
			ft_debug_ls_struct.c \
			ft_free_ls_struct.c \
			ft_fill_perms.c \
			ft_append_direntry.c \
			ft_ls_str_alphacmp.c \
			ft_fill_owners.c \
			ft_fill_last_mod.c \
			ft_handle_err.c \
			ft_parse_options.c \
			ft_parse_params.c \
			ft_print_usage.c \
			ft_get_stats.c \
			ft_create_ls_elem.c \
			ft_strjoin_path.c \
			ft_create_folder_elems_ll.c \
			ft_ls_output.c \
			ft_can_recurse.c \
			ft_is_option.c \
			ft_ls_output_dir_elems.c \
			ft_get_rdev_infos.c \
			ft_init_colors.c \
			ft_debug_ls_colors.c \
			ft_ls_follow_symlink.c \
			main.c

ifeq ($(UNAME_S),Darwin)
	SRC_NAME += ft_fill_ext_attr_acl.c
endif

SRC_DIR = ./srcs/
INCLUDES_DIR = ./includes/
OBJ_DIR = ./objs/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEV_FLAGS = -fsanitize=address -fno-omit-frame-pointer
IFLAGS = -I./ft_printf/includes -I./$(INCLUDES_DIR)
LFLAGS = -L./ft_printf -lftprintf

CFLAGS += $(DEV_FLAGS)
FT_PRINTF_DIR = ./ft_printf
LIBFTPRINTF = $(addprefix $(FT_PRINTF_DIR),"/libftprintf.a")

MAKEFILE_STATUS = $(addprefix $(addprefix $(FT_PRINTF_DIR),"/libft"),"/.makefile_status")

UNAME_S := $(shell uname -s)

define ui_line
	$(MAKEFILE_STATUS) $(1) $(2) || true
endef

all : $(NAME)

$(NAME) : $(LIBFTPRINTF) $(OBJ)
	@cp $(LIBFTPRINTF) ./libftprintf.a
ifeq ($(UNAME_S),Linux)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFTPRINTF) -o $(NAME)
endif
ifeq ($(UNAME_S),Darwin)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
endif

$(OBJ_DIR)%.o : $(SRC_DIR)%.c ./includes/ft_ls.h
	@mkdir -p $(OBJ_DIR)
	@cp ft_printf/includes/ft_printf.h ft_printf/includes/libft_printf.h
	@gcc $(CFLAGS) -c $(IFLAGS) $< -o $@ && $(call ui_line, $@, $(NAME))

$(FT_PRINTF_DIR):
	@git clone https://github.com/jjaniec/ft_printf 2> /dev/null || true

$(LIBFTPRINTF): $(FT_PRINTF_DIR)
	make -C ft_printf

output_tests:
	git clone https://github.com/asciimoo/exrex.git || true
	chmod +x ./.output_tests.sh
	./.output_tests.sh

fuzzing_tests:
	git clone https://github.com/aoh/radamsa.git || true
	make -C radamsa
	chmod +x ./.radamsa_input_tests.sh
	./.radamsa_input_tests.sh

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ft_printf/

fclean: clean
	@make fclean -C ft_printf/
	@rm -f $(NAME)
	@rm ft_printf/includes/libft_printf.h || true

re: fclean all

.PHONY: clean fclean all re input_tests
