/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:50:18 by esali             #+#    #+#             */
/*   Updated: 2023/03/26 17:13:25 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**g_c_map;

//if exit found, is checking if there is a P arround
int	check_surrounding(int y, int x)
{
	int	is_reached;

	is_reached = 0;
	if (g_c_map[y - 1][x] == 'P' || g_c_map[y + 1][x] == 'P')
		is_reached = 1;
	if (g_c_map[y][x + 1] == 'P' || g_c_map[y][x - 1] == 'P')
		is_reached = 1;
	return (is_reached);
}

//checks if no C is left and E is reached, returns zero if not reached
int	no_c(void)
{
	int	x;
	int	y;
	int	is_reached;

	y = 1;
	is_reached = 0;
	while (g_c_map[y] != 0)
	{
		x = 0;
		while (g_c_map[y][x] != 0)
		{
			if (g_c_map[y][x] == 'C')
				return (0);
			if (g_c_map[y][x] == 'E')
			{
				is_reached = check_surrounding(y, x);
			}
			x++;
		}
		y++;
	}
	return (is_reached);
}

// checks recursive; returns 1 if there is path
int	is_path(int y, int x)
{
	if (g_c_map[y + 1][x] == '0' || g_c_map[y + 1][x] == 'C' )
	{
		g_c_map[y + 1][x] = 'P';
		if (is_path(y + 1, x))
			return (1);
	}
	if (g_c_map[y][x - 1] == '0' || g_c_map[y][x - 1] == 'C' )
	{
		g_c_map[y][x - 1] = 'P';
		if (is_path(y, x - 1))
			return (1);
	}
	if (g_c_map[y - 1][x] == '0' || g_c_map[y - 1][x] == 'C' )
	{
		g_c_map[y - 1][x] = 'P';
		if (is_path(y - 1, x))
			return (1);
	}
	if (g_c_map[y][x + 1] == '0' || g_c_map[y][x + 1] == 'C' )
	{
		g_c_map[y][x + 1] = 'P';
		if (is_path(y, x + 1))
			return (1);
	}
	return (no_c());
}

//searches player and starts recursive func is_path
int	ret_is_path(void)
{
	int	y;
	int	x;

	y = 0;
	while (g_c_map[y])
	{
		x = 0;
		while (g_c_map[y][x])
		{
			if (g_c_map[y][x] == 'P')
				return (is_path(y, x));
			x++;
		}
		y++;
	}
	return (0);
}

//copys map and calls ret_is_path
int	check_path(char	**map, int row)
{
	int	y;
	int	ret;

	g_c_map = (char **) malloc(sizeof(char *) * (row + 1));
	if (!g_c_map)
		return (0);
	y = 0;
	while (y < row)
	{
		g_c_map[y] = ft_strdup(map[y]);
		y++;
	}
	g_c_map[row] = 0;
	ret = ret_is_path();
	free_map(g_c_map);
	return (ret);
}
