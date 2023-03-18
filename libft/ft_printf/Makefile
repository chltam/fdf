# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <htam@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 19:12:42 by htam              #+#    #+#              #
#    Updated: 2023/03/17 23:40:55 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := @cc
CFLAGS := -Werror -Wextra -Wall
SRCS := ft_printf.c \
		print_char.c \
		print_number.c \
		print_hex.c
OBJS := $(SRCS:.c=.o)
$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)
		

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
re: fclean all
