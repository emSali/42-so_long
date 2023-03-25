/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:34:24 by esali             #+#    #+#             */
/*   Updated: 2023/03/18 11:46:28 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	g_count_move;
int	g_pos_y;
int	g_pos_x;

void	end_game(t_win *win)
{
	printf("\nWell done! You finished the game in %i_moves", g_count_move);
	exit_window(win);
}

int	check_move(char c, t_win *win)
{
	int	x;
	int y;

	if (c == '0' || c == 'C')
		return (1);
	if (c == '1')
		return (0);
	y = 0;
	while(win->map[y])
	{
		x = 0;
		while(win->map[y][x])
		{
			if (win->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	end_game(win);
	return (1);
}

int	move(int key_code, t_win *win)
{
	if (key_code == KEY_W && check_move(win->map[g_pos_y - 1][g_pos_x], win))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.empty, 64 * g_pos_x, 64 * g_pos_y);
		win->map[g_pos_y][g_pos_x] = '0';
		g_pos_y -= 1;
		win->map[g_pos_y][g_pos_x] = 'P';
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.player, 64 * g_pos_x, 64 * g_pos_y);
		return (1);
	}
	if (key_code == KEY_D && check_move(win->map[g_pos_y][g_pos_x + 1], win))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.empty, 64 * g_pos_x, 64 * g_pos_y);
		win->map[g_pos_y][g_pos_x] = '0';
		g_pos_x += 1;
		win->map[g_pos_y][g_pos_x] = 'P';
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.player, 64 * g_pos_x, 64 * g_pos_y);
		return (1);
	}
	if (key_code == KEY_A && check_move(win->map[g_pos_y][g_pos_x - 1], win))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.empty, 64 * g_pos_x, 64 * g_pos_y);
		win->map[g_pos_y][g_pos_x] = '0';
		g_pos_x -= 1;
		win->map[g_pos_y][g_pos_x] = 'P';
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.player, 64 * g_pos_x, 64 * g_pos_y);
		return (1);
	}
	if (key_code == KEY_S && check_move(win->map[g_pos_y + 1][g_pos_x], win))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.empty, 64 * g_pos_x, 64 * g_pos_y);
		win->map[g_pos_y][g_pos_x] = '0';
		g_pos_y += 1;
		win->map[g_pos_y][g_pos_x] = 'P';
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image.player, 64 * g_pos_x, 64 * g_pos_y);
		return (1);
	}
	return (0);
}

int	key_pressed(int key_code, t_win *win)
{
	if (key_code == KEY_ESC)
		exit_window(win);
	if (key_code == KEY_W || key_code == KEY_D || key_code == KEY_S || key_code == KEY_A) 
	{
		if (move(key_code, win))
			ft_printf("\nnr. of moves: %i", ++g_count_move);
	}
	return (1);
}

void	set_start(char **map)
{
	int	y;
	int x;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				g_pos_y = y;
				g_pos_x = x;
			}
			x++;
		}
		y++;
	}
	g_count_move = 0;
}