#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:43:01 by pmorin            #+#    #+#              #
#    Updated: 2019/01/18 16:01:05 by pmorin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= wolf3d
LIB= libft/libft.a minilibx_macos/libmlx.a
FLAGS= -Wall -Wextra -Werror
CC= gcc
_GREEN= $'\x1b[32m'
SRCS= srcs/check_map.c srcs/free_map.c srcs/main.c srcs/hook.c srcs/hook2.c \
		srcs/init.c srcs/set_pixel.c srcs/calc.c srcs/draw.c srcs/draw2.c\
        srcs/utils.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)
	@echo "${_GREEN}wolf3d is ready !${_GREEN}"

$(NAME): $(OBJS)
	@make -C minilibx_macos/
	@make -C libft/
	@gcc -o $@ $(OBJS) $(LIB) -framework OpenGL -framework AppKit

.c.o:
	$(CC) -c $^ -o $@ $(FLAGS) -I libft/ -I minilibx_macos/ -I includes/

.PHONY: clean

clean:
	rm -f srcs/*.o
	rm -f libft/*.o
	rm -f minilibx_macos/*.o

fclean: clean
	rm -f wolf3d
	rm -f libft/libft.a
	rm -f minilibx_macos/libmlx.a

re: fclean all
