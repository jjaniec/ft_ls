# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 21:53:56 by jjaniec           #+#    #+#              #
#    Updated: 2018/03/14 14:46:48 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_NAME = 	ft_append_elem.c \
			ft_colorize_name.c \
			ft_debug_ls_struct.c \
			ft_free_ls_struct.c \
			ft_fill_perms.c \
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
			main.c

SRC_DIR = ./srcs/
INCLUDES_DIR = ./includes/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./ft_printf/includes -I./$(INCLUDES_DIR)
LFLAGS = -L./ft_printf -lftprintf

FT_PRINTF = ./ft_printf

UNAME_S := $(shell uname -s)

all : $(NAME)

.PHONY : all clean

$(NAME) : $(FT_PRINTF) $(OBJ)
	cp ./ft_printf/libftprintf.a ./libftprintf.a
ifeq ($(UNAME_S),Linux)
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)
endif
ifeq ($(UNAME_S),Darwin)
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
endif

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	cp ft_printf/includes/ft_printf.h ft_printf/includes/libft_printf.h
	gcc $(CFLAGS) -c $(IFLAGS) $^ -o $@

$(FT_PRINTF):
	git clone https://github.com/jjaniec/ft_printf || true
	make -C ft_printf

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ft_printf/

fclean: clean
	make fclean -C ft_printf/
	rm -f $(NAME)
	rm ft_printf/includes/libft_printf.h

re: fclean all
