# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/21 23:32:37 by vtouffet          #+#    #+#              #
#    Updated: 2017/07/23 18:55:37 by vtouffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=eval_expr
SRCS=srcs/*.c

all:
	@gcc $(SRCS) -o $(NAME) -g

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
