# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robegarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:51:10 by robegarc          #+#    #+#              #
#    Updated: 2023/02/10 10:51:15 by robegarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractal.c algos.c event.c
COMP = gcc -Wall -Wextra -Werror -Ofast
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = fractal
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@$(COMP) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean :	clean
	@rm -rf $(NAME)

re :	fclean all

.PHONY: clean fclean re all
