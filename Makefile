NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror


INCLUDE = -I include/so_long.h -I libft -I mlx
INCLUDE_BONUS = -I include/so_long_bonus.h -I libft -I mlx
MLX_LIB = -L mlx -lmlx -framework OpenGL -framework AppKit

LIB = -Llibft -lft $(MLX_LIB)

MLX = mlx/libmlx.a
LIBFT = libft/libft.a

RM = rm -f

SRCS =	./src/so_long.c \
		./src/check_map_file.c \
		./src/check_map_parsing.c \
		./src/check_map_requirements.c \
		./src/check_map_complete.c \
		./src/check_map_solvable.c \
		./src/game_init.c \
		./src/game_display.c \
		./src/game_actions.c \
		./src/error_exit.c

OBJS = $(SRCS:%.c=%.o)

BONUS =	./bonus/so_long_bonus.c \
		./bonus/check_map_parsing_bonus.c \
		./bonus/check_map_requirements_bonus.c \
		./bonus/check_map_complete_bonus.c \
		./bonus/check_map_solvable_bonus.c \
		./bonus/game_init_bonus.c \
		./bonus/game_display_bonus.c \
		./bonus/game_actions_bonus.c \
		./bonus/error_exit_bonus.c \

OBJS_B = $(BONUS:%.c=%.o)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(MLX) $(LIBFT) $(OBJS)
			@echo " [ .. ] | Compiling so_long.."
			$(CC) $(FLAGS) $(INCLUDE) $(OBJS) $(LIB) -o $(NAME)
			@echo " [ OK ] | so_long ready!"

bonus:		$(LIBFT) $(OBJS_B)
			@echo " [ .. ] | Compiling so_long.."
			$(CC) $(FLAGS) $(INCLUDE_BONUS) $(OBJS_B) -Llibft -lft -o $(NAME)
			@echo " [ OK ] | so_long bonus ready!"

# bonus:		$(MLX) $(LIBFT) $(OBJS_B)
# 			@echo " [ .. ] | Compiling so_long.."
# 			$(CC) $(FLAGS) $(INCLUDE_BONUS) $(OBJS_B) $(LIB) -o $(NAME)
# 			@echo " [ OK ] | so_long bonus ready!"

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
			@($(RM) $(OBJS) $(OBJS_B))
			@echo " [ OK ] | Objects removed!"

fclean: 	clean
			@echo " [ .. ] | Cleaning libraries and executable.."
			@make -s -C libft fclean
			@($(RM) $(NAME))
			@echo " [ OK ] | Everything is clean!"

re: 		fclean all

reb:		fclean bonus

.PHONY:		all bonus clean fclean re
