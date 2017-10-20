# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 10:02:17 by fsabatie          #+#    #+#              #
#    Updated: 2017/07/23 23:28:19 by fsabatie         ###   ########.fr        #
#    Updated: 2017/07/23 11:28:40 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

all:
	gcc -Wall -Wextra -Werror -c ft_calcs.c ft_list_operations.c \
	main.c ft_make_square.c ft_compare.c 
	gcc -Wall -Wextra -Werror ft_calcs.o ft_list_operations.o \
	main.o ft_make_square.o ft_compare.o -o $(NAME)

clean:
	rm -f ft_calcs.o ft_list_operations.o main.o ft_make_square.o ft_compare.o

fclean: clean
	rm -f $(NAME)

re: fclean all
