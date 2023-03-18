# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <htam@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 15:48:02 by htam              #+#    #+#              #
#    Updated: 2023/03/18 16:18:55 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CFLAGS := -Wall -Werror -Wextra
MLX := minilibx-linux
INCLUDE := -I$(MLX) -Ilibft
LIBRARY := -Llibft -lft -L$(MLX) -lmlx_Linux -lXext -lX11 -lm -lz
CC := cc
SCRS := fdf.c init.c image.c coordinate.c line.c rotation.c hook.c free.c

$(NAME) : $(MLX) $(SCRS) 
	@make -C libft
	$(CC) $(SCRS) $(INCLUDE) $(LIBRARY) -O3 -o $(NAME)

$(MLX) :
	@echo "mlx not found, downloading..."
	wget -q https://projects.intra.42.fr/uploads/document/document/13502/minilibx-linux.tgz
	tar -xvf minilibx-linux.tgz
	rm minilibx-linux.tgz
	@make -C $(MLX)
all : $(NAME)

clean :
	rm -rf $(NAME)

fclean :
	make fclean -C libft
	rm -rf $(NAME)
	rm -rf $(MLX)

re : fclean all

.PHONY : clean fclean re
