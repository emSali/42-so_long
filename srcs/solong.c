/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:58 by esali             #+#    #+#             */
/*   Updated: 2023/03/08 12:32:05 by esali            ###   ########.fr       */
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

/*
t_img	new_img(void *mlx_ptr) {
	int		h;
	int		w;
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, "./character.xpm", &h, &w);
	return ((t_img) {img, h, w});
}

//create window structure and initialize it
t_win	new_window(int w, int h, char *str)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_pos	pos;
	t_img	image;

	mlx_ptr = mlx_init(); //create program instance
	win_ptr = mlx_new_window(mlx_ptr, w, h, str); //window pointer -> instance of window
	pos = ((t_pos) {10, 10});
	image = new_img(mlx_ptr);
	return ((t_win) {mlx_ptr, win_ptr, w, h, image, pos});
}

t_img	*new_img(t_win window)
{
	t_img	*image;

	image = malloc(sizeof(t_img) * 1);
		if (!image)
			return image;
	image->win = window;
	image->img_ptr = mlx_xpm_file_to_image(image->win.mlx_ptr, "coins_new.xpm", &image->width, &image->height);
	//image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	//image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian)); // gets data adress of current image
	return (image);
}
*/

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 300, 300, "SoLong");
	if (!win.mlx_ptr || !win.win_ptr)
		return (1);

	win.image.player = mlx_xpm_file_to_image(win.mlx_ptr, "./assets/player.xpm", &win.image.width, &win.image.height);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.image.player, 150, 150); //put image to coorrdinates [10, 10]


	mlx_hook(win.win_ptr, 17, 0, exit_window, &win);
	mlx_loop(win.mlx_ptr); //infinite loop to keep program running and window open
	return (0);

}
