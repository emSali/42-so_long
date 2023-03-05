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


//put color at dst and make  sure it is inside picture size
void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	//protect image border
	if (x >= 0 && y >= 0 && x < img.width && y < img.height) {
		/*
		(line_len * y) is the start of the colum on the addr.
		(bpp / 8) where 8 represents 8 bits per character, to find out how many bytes is one pixel.
		(x * (bpp / 8)) is the column of the pixel
		*/
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

//create image struct with all data needed for image
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
		
	image = new_img(300, 300, win);
	put_pixel_img(image, 150, 150, 0x00FF0000);
	mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 10, 10); //put 4x4 pixel to coorrdinates [10, 10]

	mlx_loop(win.mlx_ptr); //infinite loop to keep program running and window open
	return (0);

}
