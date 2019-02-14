
#include "fdf.h"

/* Fonction de projection parallele, on calcule les nouveaux x et y
 * en fonction de l'alt z, la proj utilise une constante a */

void  ft_proj_p(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2)
{
		int x1_new;
		int x2_new;
		int y1_new;
		int y2_new;
		int a;

		a = 1;
		x1_new = x1 + a * z1;
		x2_new = x2 + a * z2;
		y1_new = y1 + (a / 2) * z1;
		y2_new = y2 + (a / 2) * z2;
		ft_line(mlx, x1_new, y1_new, x2_new, y2_new);
}

/*Parcoure la map, envoie les points a la fonct de proj, et ajoute le gap 
 * Il manque le tracage des bordures ext droite et bas ;) */

int		ft_draw_map(t_mlx *mlx, int gap)
{
	int x;
	int y;
	int **tab;

	tab = mlx->map->tab;
	y = 0;
	while (y < (mlx->map->y_tab - 1))
	{
		x = 0;
		while (x < (mlx->map->x_tab - 1))
	 {
			ft_proj_p(mlx, x * gap, y * gap, tab[y][x], (x + 1) * gap, y * gap, tab[y][x + 1]);
			ft_proj_p(mlx, x * gap, y * gap, tab[y][x], x * gap, (y + 1) * gap, tab[y + 1][x]);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_swap_int(int *nb1, int *nb2)
{
	int	tmp;

	tmp = *nb2;
	*nb2 = *nb1;
	*nb1 = tmp;
}

/* modification du else if pour prendre en compte le cas ou y varie et pas y */

int	ft_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	int x;
	int y;
	int color;

	color = 65535;
	if (x1 != x2 && y1 != y2)
		color = 16765404;
	if (x1 > x2)
	{
		ft_swap_int(&x1, &x2);
		ft_swap_int(&y1, &y2);
	}
	if ((x2 - x1) > (y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			mlx_pixel_put(mlx->ptr, mlx->wdw, x, y1 + ((y2 - y1)*(x - x1 )) / (x2 - x1), color);
			x++;
		}
	}
	else if ((y2 - y1) > (x2- x1))
	{
		y = y1;
		while (y <= y2)
		{
			mlx_pixel_put(mlx->ptr, mlx->wdw, x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), y, color);
			y++;
		}
	}
	return (0);
}
