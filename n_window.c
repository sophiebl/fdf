#include "fdf.h"

int		deal_key(int key, t_mlx *param)
{
	ft_putchar(key + 97);
	if (1)
	{
		mlx_string_put(param->ptr, param->wdw, 130, 250, 16678812, "Touche U");
	}
	return (0);
}

int		draw_line(void *mlx_ptr, void *mlx_wdw, int x1, int y1, int x2, int y2)
{
	int x;
	
	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx_ptr, mlx_wdw,x, y1+((y2-y1)*(x-x1)) / (x2-x1) ,65535);
		x++;
	}
	return (0);
}


int		n_window(void)
{
	void	*mlx_ptr;
	void	*mlx_wdw;
	int		i;
	t_mlx	*param;
	static char *xpm[] = {
	"24 20 3 1",
	" 	c None",
	".	c #3A32E4",
	"+	c #E43232",
	"                        ",
	"    ..                  ",
	"   ....                 ",
	"  ......++++++++        ",
	" .........+++++++       ",
	" ..........+++++++      ",
	" ............++++++     ",
	" .............++++++    ",
	"  ..............++++    ",
	"   +.............+++    ",
	"   ++.............++    ",
	"   +++.............+    ",
	"   +++++.............   ",
	"   ++++++.............. ",
	"   ++++++++............ ",
	"   +++++++++........... ",
	"    +++++++++.........  ",
	"     ++++++++++.......  ",
	"      ++++++++++.....   ",
	"       +++++++++ ...    "};
	
	mlx_ptr = mlx_init();
	mlx_wdw = mlx_new_window(mlx_ptr, 2000, 1000, "Hello World!");
   	mlx_string_put(mlx_ptr, mlx_wdw, 130, 50, 16678812, "Hello World!");
	i = 20;
	while (i <= 30)
	{
		mlx_pixel_put(mlx_ptr, mlx_wdw, 100, i, 65535);
		mlx_pixel_put(mlx_ptr, mlx_wdw, 101, i, 65535);
		i++;
	}
	draw_line(mlx_ptr, mlx_wdw, 0, 125, 800, 125);
	param = malloc(sizeof(t_mlx));
	param->ptr = mlx_ptr;
	param->wdw = mlx_wdw;
	param->img_h = 600;
	param->img_w = 800;
	param->img = mlx_xpm_to_image(mlx_ptr, xpm, &(param->img_w), &(param->img_w));
	mlx_put_image_to_window(param->ptr , param->wdw , param->img, 200, 200);

	mlx_key_hook(mlx_wdw, deal_key, param);
	mlx_loop(mlx_ptr);
	return (0);
}
