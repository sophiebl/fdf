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


int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);	
		parser(fd);
	}
/*	void	*mlx_ptr;
	void	*mlx_wdw;
	int		i;
	t_mlx	*param;
	char	*test;
	
	mlx_ptr = mlx_init();
	mlx_wdw = mlx_new_window(mlx_ptr, 1000, 600, "Hello World!");
   	mlx_string_put(mlx_ptr, mlx_wdw, 130, 50, 16678812, "Hello World!");
	i = 20;
	while (i <= 30)
	{
		mlx_pixel_put(mlx_ptr, mlx_wdw, 100, i, 65535);
		mlx_pixel_put(mlx_ptr, mlx_wdw, 101, i, 65535);
		i++;
	}
	param = malloc(sizeof(t_mlx));
	param->ptr = mlx_ptr;
	param->wdw = mlx_wdw;

	mlx_key_hook(mlx_wdw, deal_key, param);
	mlx_loop(mlx_ptr);*/
	return (0);
}
