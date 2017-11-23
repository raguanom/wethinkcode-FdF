#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/16 14:16:26 by raguanom          #+#    #+#              #
#    Updated: 2017/11/13 11:09:32 by raguanom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -o $(NAME) -I includes/ -I libft/ -lmlx -framework OpenGL -framework AppKit

CFILES = source/draw.c source/init_map.c source/key_events.c source/main.c source/aux.c libft/libft.a

$(NAME):
	$(MAKE) -C libft all
		$(CC) $(CFILES) $(CFLAGS)

all: $(NAME)

clean:
	$(MAKE) -C libft clean

fclean:
	$(MAKE) -C libft fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: run re fclean clean all
