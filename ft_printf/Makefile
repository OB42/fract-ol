# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#               #
#   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

SRC = ft_atos.c error.c ft_write_count.c padding.c parse_specifier.c get_next_arg.c big.c sml.c ft_write_count.c ft_putwcharstr.c ft_printf.c ft_voidstrlen.c ft_ntchar.c ft_skip_digits.c ft_indexof.c ft_wcslen.c ft_lltoa.c ft_ulltoa_base.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c

BIN = $(SRC:.c=.o)

NAME = libft.a

$(NAME):
	gcc -Wall -Wextra -Werror -c -I./includes $(SRC)
	ar -rc $(NAME) $(BIN)

clean:
	/bin/rm -f $(BIN)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

all: $(NAME)
