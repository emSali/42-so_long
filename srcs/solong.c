/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:58 by esali             #+#    #+#             */
/*   Updated: 2023/03/18 11:47:12 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//function called from mlx_hook() to end programm
int	exit_window(t_win *window)
{
	if (window)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr); //destroys window accordingly (frees?)
	exit(EXIT_SUCCESS);
}

t_img	add_assets(void *mlx_ptr)
{
	t_img	image;

	image.player = mlx_xpm_file_to_image(mlx_ptr, \
	"./assets/player.xpm", &image.width, &image.height);
	image.exit = mlx_xpm_file_to_image(mlx_ptr, \
	"./assets/treasure.xpm", &image.width, &image.height);
	image.empty = mlx_xpm_file_to_image(mlx_ptr, \
	"./assets/grass.xpm", &image.width, &image.height);
	image.wall = mlx_xpm_file_to_image(mlx_ptr, \
	"./assets/wall.xpm", &image.width, &image.height);
	image.collectible = mlx_xpm_file_to_image(mlx_ptr, \
	"./assets/coins.xpm", &image.width, &image.height);
	return (image);
}

int	check_arg(int argc, char *argv[])
{
	int		len;
	char	*str;

	if (argc != 2 || ft_strlen(argv[1]) < 5)
	{
		ft_printf("\n2 arguments needed, 2. ending with .ber");
		return (1);
	}
	len = ft_strlen(argv[1]);
	str = ft_substr(argv[1], len - 4, 4);
	if (ft_strncmp(".ber", str, 4) != 0)
	{
		ft_printf("\nThe argument needs to be of type .ber");
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_win	win;

	if (check_arg(argc, argv))
		return (0);
	win.map = save_map(argv[1], &win.height, &win.width);
	if (win.map == NULL)
		return (1);
	if (check_map(win))
		return (1);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, \
	win.width * 64, win.height * 64, "SoLong");
	if (!win.mlx_ptr || !win.win_ptr)
		return (1);
	win.image = add_assets(win.mlx_ptr);
	put_map(win.mlx_ptr, win.win_ptr, win.image, win.map);
	set_start(win.map);
	mlx_key_hook(win.win_ptr, key_pressed, &win);
	mlx_hook(win.win_ptr, 17, 0, exit_window, &win);
	mlx_loop(win.mlx_ptr); //infinite loop to keep program running and window open
	return (0);
}
