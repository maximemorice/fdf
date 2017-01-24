# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmorice <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:55:34 by mmorice           #+#    #+#              #
#    Updated: 2016/12/13 18:22:34 by mmorice          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_putchar_fd.c ft_atoi.c \
	   ft_memccpy.c ft_putchar.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
	   ft_strcpy.c ft_strlen.c ft_strdup.c ft_putnbr_fd.c ft_putendl_fd.c \
	   ft_putendl.c ft_putnbr.c ft_itoa.c ft_isdigit.c ft_isalpha.c \
	   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	   ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strsplit.c ft_strtrim.c \
	   ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strmapi.c \
	   ft_strmap.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_striteri.c \
	   ft_striter.c ft_strclr.c ft_strdel.c ft_strncat.c ft_memmove.c \
	   ft_strchr.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strstr.c \
	   ft_strnstr.c ft_strrchr.c get_next_line.c
OBJS = $(addsuffix .o, $(basename $(SRCS)))

.PHONY: all clean re fclean

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -I ./ -o $@ -c $<
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
