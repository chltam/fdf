# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <htam@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 15:48:02 by htam              #+#    #+#              #
#    Updated: 2023/03/10 17:22:18 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CFLAGS := -Wall -Werror -Wextra
INCLUDE := -Imlx_linux -Ilibft
LIBRARY := -Llibft -lft -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
CC := cc
SCRS := fdf.c init.c image.c free.c

$(NAME) : $(SCRS)
	@make -C libft
	$(CC) $(SCRS) $(INCLUDE) $(LIBRARY) -O3 -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(NAME)

fclean :
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all