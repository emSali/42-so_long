# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 19:37:29 by esali             #+#    #+#              #
#    Updated: 2023/02/21 21:18:21 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= srcs/solong.c

OBJS 		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address -g
RUN			= ar rcs
NAME 		= solong

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(NAME) $(OBJS)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(OBJS)

re: fclean all
