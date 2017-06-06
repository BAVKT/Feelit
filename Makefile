# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 16:11:48 by vmercadi          #+#    #+#              #
#    Updated: 2017/06/02 16:11:01 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	srcs/check.c srcs/fillit.c srcs/resolution.c srcs/set.c srcs/various.c \
		srcs/cube.c srcs/move.c srcs/utilist.c

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

SRCO = $(SRC:%.c=%.o)

INCLUDES = includes

.PHONY: all re clean

all: $(NAME)

$(NAME):
	@make re -C libft/
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all
