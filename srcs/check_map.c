/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:34:20 by esali             #+#    #+#             */
/*   Updated: 2023/03/12 18:55:16 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//returns 1 if invalid
int	check_map(t_win win)
{
	int	len;
	int	row;

	len = ft_strlen(win.map[0]);
	row = 0;
	while (win.map[row] != NULL)
		row++;
	if (c_size(win.map, len) || c_comp(win.map) || c_wall(win.map, len, row))
	{
		free_map(win.map);
		return (1);
	}
	if (check_path(win.map, row) == 0)
	{
		ft_printf("\nERROR: There is no possible path");
		free_map(win.map);
		return (1);
	}
	else if (check_path(win.map, row) == 1)
		ft_printf("\nThe Path is possible");
	else if (check_path(win.map, row) == 2)
		ft_printf("\nIs_Path did not return");
	return (0);
}

int	check_size(char **map, size_t len)
{
	while (*map)
	{
		if (ft_strlen(*map) != len)
		{
			ft_printf("\nERROR: Map must be rectangular");
			return (1);
		}
		map++;
	}
	return (0);
}

char	check_components_row(char *row, int *epc)
{
	int		j;
	char	ret;

	j = 0;
	while (row[j])
	{
		if (row[j] == 'P')
			epc[0]++;
		else if (row[j] == 'E')
			epc[1]++;
		else if (row[j] == 'C')
			epc[2]++;
		else if (row[j] != '0' && row[j] != '1')
			ret = row[j];
		j++;
	}
	return (ret);
}

//checks if 1 E, 1 P and > 1 C
//epc: exit, player, collectible
int	check_comp(char **map)
{
	int		i;
	int		epc[3];
	char	ret;

	i = 0;
	while (i < 3)
		epc[i++] = 0;
	i = 0;
	while (map[i])
	{
		ret = check_components_row(map[i], epc);
		i++;
	}
	if (epc[0] != 1 || epc[1] != 1 || epc[2] == 0)
	{
		ft_printf("\nERROR: The Map must contain: 1 exit, 1, >= 1 collectible.");
		return (1);
	}
	if (ret)
	{
		ft_printf("\nERROR: %c is not an allowed character", ret);
		return (1);
	}
	return (0);
}

int	check_wall(char	**map, int len, int row)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1')
			ret = 1;
		if (map[row - 1][i] != '1')
			ret = 1;
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (map[i][0] != '1')
			ret = 1;
		if (map[i][len - 1] != '1')
			ret = 1;
		i++;
	}
	if (ret == 1)
		printf("\nERROR: The map must be surrounded by walls");
	return (ret);
}
