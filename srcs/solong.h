/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:37:32 by esali             #+#    #+#             */
/*   Updated: 2023/03/12 10:37:52 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

typedef struct	s_img // struct representing image
{
	void	*empty; //address of mlx image instance empty
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		height; //image-height
	int		width; //image-width
}		t_img;

typedef struct	s_win // struct representing window
{
	void	*mlx_ptr; //program instance, created through mlx_init()
	void	*win_ptr; //adress of window
	//int		height;
	// int		width;
	char	**map;
	t_img	image;
}		t_win;

int		check_wall(char	**map, int len, int row);
char	check_components_row(char *row, int *epc);
int		check_components(char **map);
void	free_map(char **map);
int		check_size(char	**map, size_t len);
int		check_map(t_win win);
void	print_map(char **map); //for testing
char	**save_map(char *str);
char	*get_next_line(int fd);
char	*concat(char *str1, char *str2);
char	*gnl(char *ret, char *save_file, int fd);
int		cpy_ret(char *ret, char *s1);

#endif
