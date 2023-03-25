# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 19:37:29 by esali             #+#    #+#              #
#    Updated: 2023/03/18 11:36:42 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	srcs/solong.c srcs/check_map.c srcs/get_next_line.c srcs/print_map.c srcs/map.c \
		srcs/check_path.c srcs/game.c

LIBFT_A = libft.a
LIBFT_DIR = libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

MLX = mlx_linux/libmlx.a

OBJS = $(SRCS:.c=.o)

RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -I.
INCLUDE			= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	gcc $(FLAGS) -c $(SRCS)
	mv *.o srcs
	gcc $(FLAGS) -fsanitize=address -g $(OBJS) $(LIBFT) $(MLX) $(INCLUDE) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
