# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 19:37:29 by esali             #+#    #+#              #
#    Updated: 2023/03/02 17:50:03 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= srcs/solong.c

MLX			= ./mlx
LIBFT		= ./libft
INMLX		= -Lmlx -lmlx
INLIBFT		= -L./libft -lft

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
RUN			= ar rcs
NAME 		= so_long

OBJS 		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $()
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)
	$(RM) $(NAME) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)
	$(RM) $(NAME) $(OBJS)

re: fclean all
