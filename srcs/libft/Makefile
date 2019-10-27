#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 13:56:16 by kkraszew          #+#    #+#              #
#    Updated: 2019/10/27 15:13:18 by kkraszew         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libft.a
SRCS	= ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_strmap.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_itoa.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstaddfront.c \
			ft_lstaddend.c \
			ft_lstpush.c \
			ft_lstdel.c \
			ft_lstprint.c \
			ft_lstaddnext.c \
			ft_isupper.c \
			ft_islower.c \
			ft_iswspace.c \
			ft_xint.c \
			ft_isblank.c \
			ft_print_bits.c \
			ft_swap_bits.c \
			ft_reverse_bits.c \
			ft_print_hex.c \
			get_next_line.c \
			ft_array_new.c \
			ft_array_pop.c \
			ft_array_print.c \
			ft_array_max_value.c \
			ft_array_copy.c \
			ft_array_rotate_left.c \
			ft_array_rotate_right.c

OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror
INC		= ./includes

all: $(NAME)
	@echo ""

norm:
	@norminette $(SRCS)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@echo "Libft: \033[0;32m" $< "\033[0m"
	@gcc -c $< -o $@ $(FLAGS) -I$(INC)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all norm clean fclean re