NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes -I libft -I mlx
MLX_LIB = -L mlx -lmlx -framework OpenGL -framework AppKit
LIB = -Llibft -lft $(MLX_LIB)

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