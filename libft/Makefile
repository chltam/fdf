# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <htam@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 11:49:25 by htam              #+#    #+#              #
#    Updated: 2023/02/28 19:27:53 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CFLAGS := -Werror -Wall -Wextra
CC := cc
files := ft_isalpha.c \
		ft_memchr.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_strtrim.c \
		ft_atoi.c \
    	ft_isascii.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_strdup.c	\
		ft_strncmp.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_itoa.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strjoin_free_s1.c \
		get_next_line.c \


files_bonus := ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

object_files :=$(files:.c=.o)
object_files_bonus :=$(files_bonus:.c=.o)


$(NAME): $(object_files)
	make -C ft_printf
	cp ./ft_printf/libftprintf.a $(NAME)
	ar -rcs $(NAME) $(object_files)
bonus: $(object_files_bonus)
	ar -rcs $(NAME) $(object_files_bonus)
all: $(NAME)
clean:
	rm -f $(object_files) $(object_files_bonus)
fclean:
	make fclean -C ft_printf
	rm -f $(object_files) $(object_files_bonus)
	rm -f libft.a
re: fclean all