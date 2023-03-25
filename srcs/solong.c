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
	t_img image;

	image.player = mlx_xpm_file_to_image(mlx_ptr, "./assets/player.xpm", &image.width, &image.height);
	image.exit = mlx_xpm_file_to_image(mlx_ptr, "./assets/treasure.xpm", &image.width, &image.height);
	image.empty = mlx_xpm_file_to_image(mlx_ptr, "./assets/grass.xpm", &image.width, &image.height);
	image.wall = mlx_xpm_file_to_image(mlx_ptr, "./assets/wall.xpm", &image.width, &image.height);
	image.collectible = mlx_xpm_file_to_image(mlx_ptr, "./assets/coins.xpm", &image.width, &image.height);

	return (image);
}

int	main(int argc, char *argv[])
{
	t_win	win;

	//write func check_argc, if wrong ending, wrong amount of arguments, etc, give message and stop program
	//is empty map working?
	if (argc != 2)
		return (1);
	win.map = save_map(argv[1], &win.height, &win.width);
	if (win.map == NULL)
		return (1);
	ft_printf("\nw: %i, h: %i", win.width, win.height);
	print_map(win.map); //remove
	if (check_map(win))
		return(1);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.width * 64, win.height * 64, "SoLong");
	if (!win.mlx_ptr || !win.win_ptr)
		return (1);
	win.image = add_assets(win.mlx_ptr);
	put_map(win);

	mlx_key_hook(win.mlx_ptr, move, &win);
	mlx_hook(win.win_ptr, 17, 0, exit_window, &win);
	mlx_loop(win.mlx_ptr); //infinite loop to keep program running and window open
	return (0);

}
