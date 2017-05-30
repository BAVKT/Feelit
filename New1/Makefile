# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 16:11:48 by vmercadi          #+#    #+#              #
#    Updated: 2017/05/08 16:37:29 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/check.c srcs/fillit.c srcs/resolution.c srcs/set.c srcs/various.c \


SRCO = $(SRC:%.c=%.o)

.PHONY: all re clean

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror $(SRC) libft/libft.a $(NAME)

clean:
	rm -rf $(SRC)

re: fclean all