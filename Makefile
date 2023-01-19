# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 09:39:39 by aaugu             #+#    #+#              #
#    Updated: 2023/01/19 09:46:30 by aaugu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes -I libft -I mlx
MLX_LIB = -Lmlx -framework OpenGL -framework AppKit
LIB = -Llibft $(MLX_LIB)

MLX = mlx/libmlx.a
LIBFT = libft/libft.a

RM = rm -f

SRCS_FILES = so_long.c
SRCS = $(addprefix ./src/, $(SRCS_FILES))

OBJS = ${SRCS:%.c=%.o}

all:		$(NAME)

$(NAME):	$(MLX) $(LIBFT) $(OBJS)
			@echo " [ .. ] | Compiling so_long.."
			$(CC) $(FLAGS) $(INCLUDES) $(LIB) $(OBJS) -o $(NAME)
			@echo " [ OK ] | so_long ready!"

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

$(LIBFT):	
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

clean:		
			@echo " [ .. ] | Cleaning objects.."
			@make -s -C libft clean
			@make -s -C mlx clean
			@($(RM) $(OBJS))
			@echo " [ OK ] | Objects removed!"

fclean: 	clean
			@echo " [ .. ] | Cleaning libraries and executable.."
			@make -s -C libft fclean
			@($(RM) $(NAME))
			@echo " [ OK ] | Everything is clean!"

re: 		fclean all

.PHONY:		all clean fclean re