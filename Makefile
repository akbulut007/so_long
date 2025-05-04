# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 18:02:24 by muhakbul          #+#    #+#              #
#    Updated: 2025/05/02 18:02:28 by muhakbul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_lstadd_front.c ft_lstlast.c \
ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstclear.c \
ft_lstdelon.c ft_lstiter.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
ft_printf/ft_print_dec.c ft_printf/ft_print_hex_lower.c \
ft_printf/ft_print_hex_upper.c ft_printf/ft_print_pointer.c \
ft_printf/ft_print_str.c ft_printf/ft_print_undec.c \
ft_printf/ft_printf.c ft_printf/ft_strlen_pf.c

OBJS = $(SRC:.c=.o)

FT_PRINTF_PATH = ft_printf

FT_PRINTF_NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
