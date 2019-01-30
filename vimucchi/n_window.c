#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, void *param)
{
	ft_putchar(key + 97);
	if (key == 85)
	{
		mlx_string_put(&param[0], &param[1], 130, 250, 16678812, "Touche U");
	
	}
	return (0);
}


int		main()
{
	void	*mlx_ptr;
	void	*mlx_wdw;
	int		i;
	void	**param;
	
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

	param = malloc(sizeof(void *) * 3);
	param[0] = mlx_ptr;
	param[1] = mlx_wdw;
	param[2] = 0;
	
	mlx_key_hook(mlx_wdw, deal_key, param);
	mlx_loop(mlx_ptr);
	return (0);
}
