#include "fdf.h"

void	ft_swap_xy(int *x1, int *x2, int *y1, int *y2)
{
	int	tmp;

	tmp = *x2;
	*x2 = *x1;
	*x1 = tmp;
	tmp = *y2;
	*y2 = *y1;
	*y1 = tmp;
}

void	get_img(t_mlx *mlx, t_color *color)
{
	int	i;
	int	j;
//	(void)p;
	t_img img[1];

	img->img_ptr = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->s_l), &(img->endian));
	//img->img_str = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->s_l), &(img->endian));
	mlx->img = img;
	j = 0;
	while (j <= mlx->map->y_tab)
	{
		i = 0;
		while (i <= mlx->map->x_tab)
		{
			img->data[WIN_WIDTH * mlx->tab_iso[j][0] + mlx->tab_iso[j][i]] = color->int_color2;
		/*	img->data[WIN_WIDTH * y + x + 1] = color >> 8;
			img->data[WIN_WIDTH * y + x + 2] = color >> 16;
			img->data[WIN_WIDTH * y + x + 3] = 0;*/
			i++;
		}
		j++;
	}

//	x = p->x1;
//	fill_pixel(img, x, y, color);
/*	if (p->x1 > p->x2)
		ft_swap_xy(&(p->x1), &(p->x2), &(p->y1), &(p->y2));
	if ((p->x2 - p->x1) > (p->y2 - p->y1))
	{
		x = p->x1;
		while (x <= p->x2)
		{
			//fill_pixel(img, x, p->y1 + ((p->y2 - p->y1) * (x - p->x1 )) / (p->x2 - p->x1), mlx_get_color_value(mlx->ptr, color));
		//	fill_pixel(img, x, p->y1 + ((p->y2 - p->y1) * (x - p->x1 )) / (p->x2 - p->x1), color->int_color2);
			img->data[WIN_WIDTH * (p->y1 + ((p->y2 - p->y1) * (x - p->x1 )) / (p->x2 - p->x1)) + x] = color->int_color2;
			x++;
		}
	}*/
	/*
	else if ((p->y2 - p->y1) > (p->x2- p->x1))
	{
		y = p->y1;
		while (y <= p->y2)
		{
			//fill_pixel(img, p->x1 + ((p->x2 - p->x1) * (y - p->y1)) / (p->y2 - p->y1), y, mlx_get_color_value(mlx->ptr, color));
		//	fill_pixel(img, p->x1 + ((p->x2 - p->x1) * (y - p->y1)) / (p->y2 - p->y1), y, color);
			img->data[WIN_WIDTH * y + (p->x1 + ((p->x2 - p->x1) * (y - p->y1)) / (p->y2 - p->y1))] = color->int_color2;
			y++;
		}
	}*/
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, img->img_ptr, 0, 0);
}

/*
void	fill_pixel(t_img *img, int x, int y, int color)
{
//	(void)x;
//	(void)y;
	int i;
	i = 0;
	//if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT &&
	//		img->s_l * (WIN_HEIGHT + 0) > img->s_l * y + x + 3)
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
	//	img->data[i] = color;
		img->data[WIN_WIDTH * y + x] = color;
		img->data[WIN_WIDTH * y + x + 1] = color >> 8;
		img->data[WIN_WIDTH * y + x + 2] = color >> 16;
		img->data[WIN_WIDTH * y + x + 3] = 0;
		i++;
	}
}*/
