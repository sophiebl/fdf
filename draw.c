
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
		color = 16711680;
	ft_line(mlx, p, color);

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
		color = 16711680;
	ft_line(mlx, p, color);
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
