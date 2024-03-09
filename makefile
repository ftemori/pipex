# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftemori <ftemori@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 12:24:07 by ftemori           #+#    #+#              #
#    Updated: 2023/11/15 12:24:10 by ftemori          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRC	= ./sources/pipex.c \
		./sources/pipex_utils.c \
		./sources/path_finder.c \
		./sources/input_check.c

CC	= cc

CFLAGS	= -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean

re:	fclean all
