#include "fdf.h"

void	ft_proj_iso(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_coord *p;
	t_color	color[1];
	int		a;
	int 	b;
	int 	offset;

	p = malloc(sizeof(t_coord));
	offset = 600;
	a = 500;
	b = 1000;
	color->int_color2 = 16857088;
	p->x1 = offset + (a * x1 - b * y1) / 1000;
	p->x2 = offset + (a * x2 - b * y2) / 1000;
	p->y1 = -z1 + ((a / 2) * x1 + (b / 2) * y1) / 1000;
	p->y2 = -z2 + ((a / 2) * x2 + (b / 2) * y2) / 1000;
	color->int_color = 65535;
	if (z1 > 0 || z2 > 0)
		color->int_color = 16761035;
	ft_pixels_to_color(mlx, p, color->int_color);
	get_img(mlx, color);
}

void  ft_proj_p(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_coord *p;
	t_color color[1];
	int		a;
	int		offset;

	p = malloc(sizeof(t_coord));
	a = -850;
	offset = 50;
	color->int_color2 = 16857088;
	p->x1 = offset + x1 + (a * z1) / 1000;
	p->x2 = offset + x2 + (a * z2) / 1000;
	p->y1 = offset + y1 + (a * z1) / 2000;
	p->y2 = offset +  y2 + (a * z2) / 2000;
	color->int_color = 65535;
	if (z1 > 0 || z2 > 0)
		color->int_color = 16761035;
	//ft_line(mlx, p, color->int_color);
	get_img(mlx, color);
}
