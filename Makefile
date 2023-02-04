# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:27:27 by kle-rest          #+#    #+#              #
#    Updated: 2023/02/04 17:12:03 by kle-rest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

LIBFT = libft.a

LIBFT_DIR = libft

LIB = $(addprefix $(LIBFT_DIR)/, $(LIBFT))

SOURCES = sortparam.c \
	print.c \
	ft_list.c \
	utils.c \
	algo.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIB)

all: $(NAME)

clean:
		rm -f $(OBJECTS)
		make clean -C libft

fclean: clean
		rm -f $(NAME)
		make fclean -C libft

re: fclean all
