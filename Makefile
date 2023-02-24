# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gimartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 15:19:09 by gimartin          #+#    #+#              #
#    Updated: 2022/02/04 15:51:35 by gimartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = ft_printf.h

SRC = ft_printf.c		number_utils.c\
			string_utils.c	print_utils.c\
			putnbr_utils.c	flag_utils.c\
			print_string_utils.c
CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
