# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 17:49:10 by muhakbul          #+#    #+#              #
#    Updated: 2025/05/02 17:49:13 by muhakbul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_print_dec.c ft_print_hex_lower.c \
ft_print_hex_upper.c ft_print_pointer.c ft_print_str.c \
ft_print_undec.c ft_strlen_pf.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
