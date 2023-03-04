/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:58 by esali             #+#    #+#             */
/*   Updated: 2023/03/02 17:11:03 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.width = w;
	image.height = h;
	return (image);
}


t_win new_window(int w, int h, char *str)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init(); //create program instance
	win_ptr = mlx_new_window(mlx_ptr, w, h, str); //window pointer -> instance of window
	return ((t_win) {mlx_ptr, win_ptr, w, h});
}


int	main(void)
{
	t_win	win;
	t_img	image;

	win = new_window(300, 300, "Game");
	if (!win.mlx_ptr || !win.win_ptr)
		return (1);
		
	image = new_img(4, 4, win);
	//if (!image.img_ptr || !image.addr)
	//	return (1);
	memcpy(image.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
	mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 10, 10); //put 4x4 pixel to coorrdinates [10, 10]

	mlx_loop(win.mlx_ptr); //infinite loop to keep program running and window open
	return (0);

}
