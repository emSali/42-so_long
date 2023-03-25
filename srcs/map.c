/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:48:02 by esali             #+#    #+#             */
/*   Updated: 2023/03/17 13:19:02 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//to shorten function change gnl to give string at once
char	**save_map(char *link, int *len, int *width)
{
	int		fd;
	char	*str;
	char	**map;
	int		i;

	fd = open(link, O_RDONLY);
	if (fd == -1)
	{
		printf("\nERROR: The map does not exist");
		return (NULL);
	}
	str = get_next_line(fd);
	if (str == NULL)
	{
		ft_printf("\nERROR: Empty map");
		return (NULL);
	}
	map = ft_split(str, '\n');
	free (str);
	if (*map == NULL)
		ft_printf("\nERROR2: Empty map");
	i = 0;
	while(map[i])
		i++;
	*len = i;
	*width = ft_strlen(map[0]);
	return (map);
}

void free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	put_map(t_win win)
{
	int	x;
	int	y;

	y = 0;
	while(win.map[y])
	{
		x = 0;
		while(win.map[y][x])
		{
			if(win.map[y][x] == '1')
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.image.wall, 64 * x, 64 * y);
			else if(win.map[y][x] == '0')
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.image.empty, 64 * x, 64 * y);
			else if(win.map[y][x] == 'E')
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.image.exit, 64 * x, 64 * y);
			else if(win.map[y][x] == 'C')
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.image.collectible, 64 * x, 64 * y);
			else if(win.map[y][x] == 'P')
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.image.player, 64 * x, 64 * y);
			x++;
		}
	y++;
	}
}

