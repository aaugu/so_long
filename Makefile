NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror


INCLUDE = -I include/game.h -I include/so_long.h -I libft -I mlx
INCLUDE_BONUS = -I include/game.h -I include/so_long_bonus.h -I libft -I mlx
MLX_LIB = -L mlx -lmlx -framework OpenGL -framework AppKit

LIB = -Llibft -lft $(MLX_LIB)

MLX = mlx/libmlx.a
LIBFT = libft/libft.a

RM = rm -f

SRCS_FILES = 	./src/so_long.c \
				./src/check_map_file.c \
				./src/check_map_parsing.c \
				./src/check_map_requirements.c \
				./src/check_map_complete.c \
				./src/check_map_solvable.c \
				./src/game_init.c \
				./src/game_display.c \
				./src/game_actions.c \
				./src/key_hook.c \

OBJS = ${SRCS:%.c=%.o}

BONUS_FILES = 	./

OBJS_B = ${SRCS_B:%.c=%.o}


%.o : %.c
	ifdef ($(MAKECMDGOALS), bonus)
		$(CC) $(FLAGS) $(INCLUDE_BONUS) -c $< -o $@
	else
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	endif
all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@echo " [ .. ] | Compiling so_long.."
			$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
			@echo " [ OK ] | so_long ready!"

bonus:		$(LIBFT) $(OBJS_B)
			@echo " [ .. ] | Compiling so_long.."
			$(CC) $(FLAGS) $(OBJS_B) $(LIB) -o $(NAME)
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
			@($(RM) $(OBJS) $(OBJS_B))
			@echo " [ OK ] | Objects removed!"

fclean: 	clean
			@echo " [ .. ] | Cleaning libraries and executable.."
			@make -s -C libft fclean
			@($(RM) $(NAME))
			@echo " [ OK ] | Everything is clean!"

re: 		fclean all

.PHONY:		all clean fclean re
