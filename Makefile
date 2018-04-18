# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 13:48:43 by vlvereta          #+#    #+#              #
#    Updated: 2018/04/18 13:49:06 by vlvereta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = vlvereta.filler

OBJ = srcs/filler.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./_includes -lft

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re