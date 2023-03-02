# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 12:03:36 by aaugu             #+#    #+#              #
#    Updated: 2023/03/02 11:05:38 by aaugu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
AR = ar rc
RM = rm -rf

LIBFT_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c  ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c  ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
LIBFT_SRCS = $(addprefix libft/, $(LIBFT_FILES))

FT_PRINTF_FILES = ft_printf.c print_c.c print_s.c print_p.c print_int.c \
print_u.c print_x.c
FT_PRINTF_SRCS = $(addprefix ft_printf/, $(FT_PRINTF_FILES))

GET_NEXT_LINE_FILES = get_next_line.c
GET_NEXT_LINE_SRCS = $(addprefix get_next_line/, $(GET_NEXT_LINE_FILES))

UTILS_FILES = ft_strcmp.c ft_free_dptr.c ft_copy_dptr.c
UTILS_SRCS = $(addprefix utils/, $(UTILS_FILES))

SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GET_NEXT_LINE_SRCS) $(UTILS_SRCS)
OBJS = $(SRCS:%.c=%.o)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
