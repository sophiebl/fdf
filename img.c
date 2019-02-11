#include "fdf.h"

void	get_img(void *mlx_ptr)
{
	img_ptr = mlx_new_image(mlx_ptr, 800, 600);
	img_str = mlx_get_data_addr(img_ptr, &(bpp), &(s_l), &(endian));
	//fill_pixel(img_str, 5, 2, 65535);
	mlx_wdw = mlx_new_window(mlx_ptr, 800, 600, "Window");
//	mlx_put_image_to_window(mlx_ptr, mlx_wdw, img_ptr, 5, 2);
}

void	fill_pixel(char *img_str, int x, int y, int color)
{
	int 	*x_pos_pix = NULL;
	int 	*y_pos_pix = NULL;
	int		i;

	x_pos_pix[0] = 0;
	x_pos_pix[1] = 0;
	x_pos_pix[2] = 0;
	x_pos_pix[3] = 0;
	y_pos_pix[0] = 0;
	y_pos_pix[1] = 0;
	y_pos_pix[2] = 0;
	y_pos_pix[3] = 0;

	i = 0;
	while (i < 4)
	{
		x_pos_pix[i] = (y + 4 * x) + i;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		y_pos_pix[i] = (x + 4 * 800 * y) + i;
		i++;
	}
	printf("x pos : %d", x_pos_pix[0]);
	printf("y pos : %d", y_pos_pix[0]);
	(void)img_str;
	(void)color;
}
