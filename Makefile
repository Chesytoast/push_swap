# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:17:32 by mcourtin          #+#    #+#              #
#    Updated: 2023/02/16 15:31:29 by mcourtin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
DIR		= srcs/
CC		= gcc 
FLAGS	= -Wall -Wextra -Werror

SRCS =	srcs/main.c srcs/parsing.c srcs/error.c srcs/stack.c srcs/utils.c \
		srcs/moves_push_swap.c srcs/moves_rotate.c srcs/moves_reverse_rotate.c \
		srcs/order.c srcs/algo.c srcs/free.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	make -C libft bonus
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L libft -lft libft/libft.a

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re