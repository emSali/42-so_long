/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:34:24 by esali             #+#    #+#             */
/*   Updated: 2023/03/26 17:00:45 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_game	g_g;

//check if move is possible and if game end possible
int	check_move(char c, t_win *win)
{
	int	x;
	int	y;

	if (c == '0' || c == 'C')
		return (1);
	if (c == '1')
		return (0);
	y = 1;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	printf("\nWell done! You finished the game in %i moves", g_g.moves);
	exit_window(win);
	return (1);
}

//change imaages when move possible
void	change_img(t_win *win, char c, int dir)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->image.empty, 64 * g_g.pos_x, 64 * g_g.pos_y);
	win->map[g_g.pos_y][g_g.pos_x] = '0';
	if (c == 'y')
		g_g.pos_y = g_g.pos_y + dir;
	if (c == 'x')
		g_g.pos_x = g_g.pos_x + dir;
	win->map[g_g.pos_y][g_g.pos_x] = 'P';
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->image.player, 64 * g_g.pos_x, 64 * g_g.pos_y);
}

//sorts key pressed and returns 1 if move possible
int	move(int key, t_win *win)
{
	if (key == KEY_W && check_move(win->map[g_g.pos_y - 1][g_g.pos_x], win))
	{
		change_img(win, 'y', -1);
		return (1);
	}
	if (key == KEY_D && check_move(win->map[g_g.pos_y][g_g.pos_x + 1], win))
	{
		change_img(win, 'x', 1);
		return (1);
	}
	if (key == KEY_A && check_move(win->map[g_g.pos_y][g_g.pos_x - 1], win))
	{
		change_img(win, 'x', -1);
		return (1);
	}
	if (key == KEY_S && check_move(win->map[g_g.pos_y + 1][g_g.pos_x], win))
	{
		change_img(win, 'y', 1);
		return (1);
	}
	return (0);
}

//is called from main when key is pressed
int	key_pressed(int key, t_win *win)
{
	if (key == KEY_ESC)
		exit_window(win);
	if (key == KEY_W || key == KEY_D || key == KEY_S || key == KEY_A)
	{
		if (move(key, win))
			ft_printf("\nnr. of moves: %i", ++g_g.moves);
	}
	return (1);
}

//sets attributes for game start in struct s_game
void	set_start(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				g_g.pos_y = y;
				g_g.pos_x = x;
			}
			x++;
		}
		y++;
	}
	g_g.moves = 0;
}
