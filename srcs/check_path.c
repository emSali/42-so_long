/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:50:18 by esali             #+#    #+#             */
/*   Updated: 2023/03/12 20:19:56 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**c_map;

//checks if no C is left and E is reached, returns zero if not reached
int no_c(){
	int	x;
	int	y;
	int is_reached;

	y = 1;
	is_reached = 0;
	while(c_map[y] != 0)
	{
		x = 0;
		while(c_map[y][x] != 0)
		{
			if (c_map[y][x] == 'C')
				return (0);
			if (c_map[y][x] == 'E')
			{
				if ((c_map[y - 1][x]) == 'P' || c_map[y + 1][x] == 'P' || c_map[y][x + 1] == 'P' || c_map[y][x - 1] == 'P')
					is_reached = 1;
			}
			x++;
		}
		y++;
	}
	return (is_reached);
}

// returns 1 if there is path
int	is_path(int y, int x)
{
	if (no_c())
		return (1);
	if (c_map[y + 1][x] == '0' || c_map[y + 1][x] == 'C' ){
		c_map[y + 1][x] = 'P';
		if (is_path(y + 1, x))
			return (1);
	}
	if (c_map[y][x - 1] == '0' || c_map[y][x - 1] == 'C' )
	{
		c_map[y][x - 1] = 'P';
		if (is_path(y, x - 1))
			return (1);
	}
	if (c_map[y - 1][x] == '0' || c_map[y - 1][x] == 'C' )
	{
		c_map[y - 1][x] = 'P';
		if (is_path(y - 1, x))
			return (1);
	}
	if (c_map[y][x + 1] == '0' || c_map[y][x + 1] == 'C' )
	{
		c_map[y][x + 1] = 'P';
		if (is_path(y, x + 1))
			return (1);
	}
	return (0);
}

int	check_path(char	**map, int row)
{
	int	x;
	int	y;
	int	ret;

	c_map = (char **) malloc(sizeof(char *) * (row + 1));
	if (!c_map)
		return (0);
	y = 0;
	while(y < row)
	{
		c_map[y] = ft_strdup(map[y]);
		y++;
	}
	c_map[row] = 0;
	y = 0;
	while(c_map[y])
	{
		x = 0;
		while(c_map[y][x])
		{
			if (c_map[y][x] == 'P')
				ret = is_path(y, x);
			x++;
		}
		y++;
	}
	free_map(c_map);
	return (ret);
}


