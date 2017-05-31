# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 16:11:48 by vmercadi          #+#    #+#              #
#    Updated: 2017/05/31 12:43:43 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	srcs/check.c srcs/fillit.c srcs/resolution.c srcs/set.c srcs/various.c \
		srcs/cube.c srcs/move.c srcs/utilist.c


SRCO = $(SRC:%.c=%.o)

.PHONY: all re clean

all: $(NAME)

$(NAME):
	make re -C libft/
	gcc -Wall -Wextra -Werror $(SRC) libft/libft.a $(NAME) -I includes/fillit.h

clean:
	rm -rf $(SRCO)

fclean: clean
	rm -rf $(NAME)

re: fclean all