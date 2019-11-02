# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:30:57 by vtran             #+#    #+#              #
#    Updated: 2019/11/02 16:53:15 by kkraszew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c create_map.c create_info.c create_lst_of_tetris.c \
		block_fx.c helper.c minxy_spot.c solver.c get_next_line.c

SRCS =$(addprefix fillit_srcs/srcs/, $(FILES))
OBJS =$(addprefix objs/, $(FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

$(OBJS): objs/%.o: fillit_srcs/srcs/%.c | objs
	@$(CC) $(CFLAGS) -o $@ -c $^

lib:
	@make -C ./libft

objs:
	@mkdir objs/

clean:
	@rm -rf objs/
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
