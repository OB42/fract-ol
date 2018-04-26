# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2017/11/30 10:33:39 by obenazzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fdf, clean, fclean, re, opti

CC = cc -O3
NAME = fdf
LFT_PATH = ./ft_printf/
SRC_NAME = fdf.c nbr_parsing.c print_error.c get_next_line/get_next_line.c pr_malloc.c split.c get_map.c draw_line.c
OBJ = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	$(CC) -I /usr/local/include -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
