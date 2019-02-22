
#include "fdf.h"

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
/*
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
}*/
