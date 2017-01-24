# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmorice <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:55:34 by mmorice           #+#    #+#              #
#    Updated: 2017/01/18 14:44:25 by mmorice          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c algo_segment.c algo_segment2.c algo_segment3.c algo_segment4.c

OBJS = $(addsuffix .o, $(basename $(SRCS)))

.PHONY: all clean re fclean

all: $(NAME)

libft/libft.a:
	make -C libft

libmlx/libmlx.a:
	make -C libmlx

$(NAME): libmlx/libmlx.a libft/libft.a  $(OBJS)
	gcc -o $(NAME) $(OBJS) libmlx/libmlx.a libft/libft.a \
		-framework OpenGL -framework Appkit
%.o: %.c
	gcc -Wall -Wextra -Werror -I ./ -I libft/ -I libmlx/ -o $@ -c $<
clean:
	make -C libft clean
	make -C libmlx clean
	rm -f $(OBJS)
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re: fclean all
