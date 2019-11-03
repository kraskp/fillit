# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 15:35:24 by kkraszew          #+#    #+#              #
#    Updated: 2019/11/03 16:34:27 by kkraszew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRC = fillit_srcs/main.c \
		fillit_srcs/create_info.c \
		fillit_srcs/create_lst_of_tetris.c \
		fillit_srcs/create_map.c \
		fillit_srcs/libfx_one.c \
		fillit_srcs/libfx_two.c \
		fillit_srcs/libfx_three.c \
		fillit_srcs/libfx_four.c \
		fillit_srcs/get_next_line.c \
		fillit_srcs/helper.c \
		fillit_srcs/solver.c \

OBJ = main.o \
		create_info.o \
		create_lst_of_tetris.o \
		create_map.o \
		libfx_one.o \
		libfx_two.o \
		libfx_three.o \
		libfx_four.o \
		get_next_line.o \
		helper.o \
		solver.o \


all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all norm clean fclean re