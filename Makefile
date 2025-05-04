# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 16:58:34 by muhakbul          #+#    #+#              #
#    Updated: 2025/05/01 16:58:38 by muhakbul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/game.c \
src/move_player.c \
src/read_map.c \
src/so_long.c \
src/map_validation/map_chars_check.c \
src/map_validation/map_form_check.c \
src/map_validation/map_is_empty_check.c \
src/map_validation/map_valid_path_check.c \
src/map_validation/map_walls_check.c \
src/helpers/create_node.c \
src/helpers/free.c \
src/helpers/helpers.c \
src/helpers/move_player_helper_func.c \
src/helpers/read_map_helper_funcs.c

OBJS = $(SRC:.c=.o)

LIBFT_PATH = libft

MLX_PATH = mlx
MLX_LIB = libmlx.a

LIBFT_NAME = libft.a

SO_LONG_NAME = so_long

$(SO_LONG_NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -lX11 -lXext $(LIBFT_PATH)/$(LIBFT_NAME) -o $(SO_LONG_NAME)

all: $(SO_LONG_NAME)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	$(RM) $(LIBFT_PATH)/ft_printf/libftprintf.a
	$(RM) $(SO_LONG_NAME)
	$(RM) $(MLX_PATH)/$(MLX_LIB)

re: fclean all
