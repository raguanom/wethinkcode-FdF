# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 07:19:41 by raguanom          #+#    #+#              #
#    Updated: 2017/09/05 14:40:41 by raguanom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CFLAGS			= -Wall -Werror -Wextra -I.
SRC				=	ft_memset.c			\
					ft_bzero.c			\
					ft_memcpy.c			\
					ft_memccpy.c		\
					ft_memmove.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_strlen.c			\
					ft_strdup.c			\
					ft_strcpy.c			\
					ft_strncpy.c		\
					ft_strcat.c			\
					ft_strncat.c		\
					ft_strlcat.c		\
					ft_strchr.c			\
					ft_strrchr.c		\
					ft_strstr.c			\
					ft_strnstr.c		\
					ft_strcmp.c			\
					ft_strncmp.c		\
					ft_atoi.c			\
					ft_isalpha.c		\
					ft_isdigit.c		\
					ft_isalnum.c		\
					ft_isascii.c		\
					ft_isprint.c		\
					ft_islower.c		\
					ft_isupper.c		\
					ft_toupper.c		\
					ft_tolower.c		\
					ft_memalloc.c		\
					ft_putnbr.c			\
					ft_putchar.c		\
					ft_striter.c		\
					ft_strjoin.c		\
					ft_putendl_fd.c		\
					ft_strequ.c			\
					ft_putnbr_fd.c		\
					ft_putstr.c			\
					ft_strclr.c			\
					ft_memdel.c			\
					ft_strmap.c			\
					ft_strsub.c			\
					ft_strsplit.c		\
					ft_strdel.c			\
					ft_putstr_fd.c		\
					ft_strnew.c			\
					ft_putendl.c		\
					ft_striteri.c		\
					ft_putchar_fd.c		\
					ft_strnequ.c		\
					ft_strtrim.c		\
					ft_itoa.c			\
					ft_strmapi.c		\
					get_next_line.c		\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -c $(SRC) $(CFLAGS) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
