
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:37:32 by esali             #+#    #+#             */
/*   Updated: 2023/03/02 17:11:42 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

typedef struct	s_img // struct representing image
{
	//void	*empty; //address of mlx image instance empty
	//void	*wall;
	//void	*collectible;
	//void	*exit;
	void	*player;
	int		height; //image-height
	int		width; //image-width
}		t_img;

typedef struct	s_win // struct representing window
{
	void	*mlx_ptr; //program instance, created through mlx_init()
	void	*win_ptr; //adress of window
	int		height;
	int		width;
	t_img	image;
}		t_win;

//t_win	new_window(int w, int h, char *str);
//int		exit_window(t_win *window);
//void	put_pixel_img(t_img img, int x, int y, int color);
//t_img	new_img(void *mlx_ptr);
#endif
