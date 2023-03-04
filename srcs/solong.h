
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

typedef struct s_win // struct representing window
{
	void	*mlx_ptr; //program instance, created through mlx_init()
	void	*win_ptr; //adress of window
	int		height;
	int		width;
}		t_win;

typedef struct s_img // struct representing image
{
	t_win	win; //window
	void	*img_ptr; //address of mlx image instance
	char	*addr; //adress, where chain of bytes starts
	int		height; //image-height
	int		width; //image-width
	int		bpp; //bits per pixel (bpp = 32 -> 4 bytes / pixel)
	int		endian; // 
	int		line_len; //number of bytes per line
}		t_img;


t_win new_window(int w, int h, char *str);

#endif
                               