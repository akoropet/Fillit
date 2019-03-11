# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 15:12:12 by dskrypny          #+#    #+#              #
#    Updated: 2018/07/27 15:12:30 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_O = $(FILES_C:.c=.o)

FILES_C = ft_open.c ft_valid.c ft_karta.c ft_valid_figury.c ft_move_figure.c \
		  ft_move_horizontal.c ft_check_place.c ft_add_square.c

LIB = libft/libft.a

NAME = fillit

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(FILES_O)
	make -C libft
	gcc $(FLAGS) $(LIB) -o $(NAME) $(FILES_O)

clean:
	rm -rf $(FILES_O)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all
	make fclean -C libft
