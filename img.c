#include "fdf.h"

void	get_img(t_mlx *mlx)
{
	t_img img[1];

	img->img_ptr = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->s_l), &(img->endian));
	mlx->img = img;
	fill_pixel(img);
//	mlx_wdw = mlx_new_window(mlx_ptr, 800, 600, "Window");
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, img->img_ptr, 0, 0);
}

void	fill_pixel(t_img *img)
{
	int        i;

	i = 50;
	while (i < 100)
	{
		img->data[i] = 0xFFFFFF;
		i++;
	}

}
