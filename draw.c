#include "fdf.h"

void	ft_swap_int(int *nb1, int *nb2)
{
	int	tmp;

	tmp = *nb2;
	*nb2 = *nb1;
	*nb1 = tmp;
	printf("nb1:%dnb2:%d\n", *nb1, *nb2);
}


int	ft_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	int x;

	if (x1 > x2)
	{
		printf("hello\n");
		ft_swap_int(&x1, &x2);
		ft_swap_int(&y1, &y2);
		printf("x1:%dx2:%d\n", x1, x2);
		printf("y1:%dy2:%d\n", y1, y2);
	}
	if ((x2 - x1) > (y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			mlx_pixel_put(mlx->ptr, mlx->wdw, x, y1+((y2-y1)*(x-x1))/(x2-x1), 65535);
			x++;
		}
	}
	else
	{
		printf("recursive\n");
		ft_line(mlx, y1, x1, y2, x2);
	}
	return (0);
}
