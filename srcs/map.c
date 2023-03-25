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
	i = 0;
	while (map[i++])
	*len = i;
	*width = ft_strlen(map[0]);
	return (map);
}

void	free_map(char **map)
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

void	put_map(void *m, void *w, t_img i, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(m, w, i.wall, 64 * x, 64 * y);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(m, w, i.empty, 64 * x, 64 * y);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(m, w, i.exit, 64 * x, 64 * y);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(m, w, i.collectible, 64 * x, 64 * y);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(m, w, i.player, 64 * x, 64 * y);
			x++;
		}
	y++;
	}
}
