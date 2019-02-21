
#include "fdf.h"

void	ft_proj_iso(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_coord *p;
	int a;
	int b;
	int color;
	int offset;

	p = malloc(sizeof(t_coord));
	offset = 600;
	a = 500;
	b = 1000;
	p->x1 = offset + (a * x1 - b * y1) / 1000;
	p->x2 = offset + (a * x2 - b * y2) / 1000;
	p->y1 = -z1 + ((a / 2) * x1 + (b / 2) * y1) / 1000;
	p->y2 = -z2 + ((a / 2) * x2 + (b / 2) * y2) / 1000;
	color = 65535;
	if (z1 > 0 || z2 > 0)
		color = 16761035;
	//ft_line(mlx, p, color);
	get_img(mlx, p, color);
}

void  ft_proj_p(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_coord *p;
	int a;
	int color;
	int offset;

	p = malloc(sizeof(t_coord));
	a = -850;
	offset = 50;
	p->x1 = offset + x1 + (a * z1) / 1000;
	p->x2 = offset + x2 + (a * z2) / 1000;
	p->y1 = offset + y1 + (a * z1) / 2000;
	p->y2 = offset +  y2 + (a * z2) / 2000;
	color = 65535;
	if (z1 > 0 || z2 > 0)
		color = 16761035;
	get_img(mlx, p, color);
	//ft_line(mlx, p, color);
}

void		ft_draw_map(t_mlx *mlx, char c)
{
	int 		x;
	int 		y;
	int			**tab;
	int			gap_x;
	int			gap_y;

	tab = mlx->map->tab;
	gap_x = (WIN_WIDTH - 25) / mlx->map->x_tab;
	gap_y = (WIN_HEIGHT - 25) / mlx->map->y_tab;
	y = 0;
	while (y < (mlx->map->y_tab - 1))
	{
		x = 0;
		while (x < (mlx->map->x_tab - 1))
		{
			if (c == 'i')
			{
				ft_proj_iso(mlx, x * gap_x, y * gap_y, tab[y][x], (x + 1) * gap_x, y * gap_y, tab[y][x + 1]);
				ft_proj_iso(mlx, x * gap_x, y * gap_y, tab[y][x], x * gap_x, (y + 1) * gap_y, tab[y + 1][x]);
			}
			if (c == 'p')
			{
				ft_proj_p(mlx, x * gap_x, y * gap_y, tab[y][x], (x + 1) * gap_x, y * gap_y, tab[y][x + 1]);
				ft_proj_p(mlx, x * gap_x, y * gap_y, tab[y][x], x * gap_x, (y + 1) * gap_y, tab[y + 1][x]);
			}
			x++;
		}
		y++;
	}
}

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

void	get_img(t_mlx *mlx, t_coord *p, int color)
{
	int	x;
	int	y;
	t_img img[1];

	img->img_ptr = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->s_l), &(img->endian));
	mlx->img = img;
	if (p->x1 > p->x2)
		ft_swap_xy(&(p->x1), &(p->x2), &(p->y1), &(p->y2));
	if ((p->x2 - p->x1) > (p->y2 - p->y1))
	{
		x = p->x1;
		while (x <= p->x2)
		{
			fill_pixel(img, x, p->y1 + ((p->y2 - p->y1) * (x - p->x1 )) / (p->x2 - p->x1), mlx_get_color_value(mlx->ptr, to_rgb(color)));
			x++;
		}
	}
	else if ((p->y2 - p->y1) > (p->x2- p->x1))
	{
		y = p->y1;
		while (y <= p->y2)
		{
			fill_pixel(img, p->x1 + ((p->x2 - p->x1) * (y - p->y1)) / (p->y2 - p->y1), y, mlx_get_color(mlx->ptr, to_rgb(color)));
			y++;
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, img->img_ptr, 0, 0);
}

void	fill_pixel(t_img *img, int x, int y, int color)
{
	//if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT &&
		//	data->sz * (WIN_HEIGHT + 0) > data->sz * y + (x * 4) + 3)
//	{
		img->data[WIN_WIDTH * y + x] = color;
		img->data[WIN_WIDTH * y + x + 1] = color >> 8;
		img->data[WIN_WIDTH * y + x + 2] = color >> 16;
		img->data[WIN_WIDTH * y + x + 3] = 0;
//	}
}

void	ft_line(t_mlx *mlx, t_coord *p, int color)
{
	int x;
	int y;

	if (p->x1 > p->x2)
		ft_swap_xy(&(p->x1), &(p->x2), &(p->y1), &(p->y2));
	if ((p->x2 - p->x1) > (p->y2 - p->y1))
	{
		x = p->x1;
		while (x <= p->x2)
		{
			mlx_pixel_put(mlx->ptr, mlx->wdw, x, p->y1 + ((p->y2 - p->y1) * (x - p->x1 )) / (p->x2 - p->x1), color);
			x++;
		}
	}
	else if ((p->y2 - p->y1) > (p->x2- p->x1))
	{
		y = p->y1;
		while (y <= p->y2)
		{
			mlx_pixel_put(mlx->ptr, mlx->wdw, p->x1 + ((p->x2 - p->x1) * (y - p->y1)) / (p->y2 - p->y1), y, color);
			y++;
		}
	}
}
