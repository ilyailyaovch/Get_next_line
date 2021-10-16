# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 19:01:58 by pleoma            #+#    #+#              #
#    Updated: 2021/10/12 19:32:23 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get-next-line

FLAGS = -Wall -Wextra -Werror
DEFINE = -D
SIZE = 1000

SRC = 	_main.c\
		get_next_line_utils.c\

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(DEFINE) BUFFER_SIZE=$(SIZE) $(SRC)