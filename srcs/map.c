/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:48:02 by esali             #+#    #+#             */
/*   Updated: 2023/03/12 10:31:57 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//to shorten function change gnl to give string at once
char	**save_map(char *link)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(link, O_RDONLY);
	if (fd == -1)
	{
		printf("\nERROR: The map does not exist");
		return (NULL);
	}
	str = get_next_line(fd);
	// TODO: check if somewhere empty line!!!
	map = ft_split(str, '\n');
	free (str);
	if (*map == NULL)
		ft_printf("\nERROR: Empty map");
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
