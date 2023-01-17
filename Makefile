# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 09:39:39 by aaugu             #+#    #+#              #
#    Updated: 2023/01/17 10:19:51 by aaugu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL_SRCS = $(addprefix(get_next_line/, $(GNL_FILES)))

SRCS = $(GNL_SRCS)

OBJ_DIR = objs
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -rf

$(OBJ_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -I./mlx -L./mlx -framework OpenGL -framework AppKit  $^ -o $(NAME)

all:			$(NAME)

bonus:			all

$(NAME):		$(OBJ_DIR) 
				$(OBJS)

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

clean:
				$(RM) $(OBJ_DIR)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY:			all bonus clean fclean re
