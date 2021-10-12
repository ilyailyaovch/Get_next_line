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

NAME = get_

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -D BUFFER_SIZE=42 _try.c -o _try.out