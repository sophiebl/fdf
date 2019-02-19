#include "fdf.h"

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_clear_window(mlx->ptr, mlx->wdw);
		exit(0);
	}
	return (0);
}


int		ft_verif(char *file)
{
	int i;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_mlx	mlx[1];

	if (ac == 3)
	{
		if (ft_verif(av[1]))
		{
			write(2, "Error:\nUsage: ./fdf <file.fdf> -p/-i\n", 35);
			exit(1);
		}
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			write(2, "Error:\nfile doesn't exist", 25);
			exit(1);
		}
		mlx->map = ft_get_tab(ft_get_map(fd));
		if (close(fd) == -1)
		{
			write(2, "Error:\nfile can't be closed", 27);
			exit(1);
		}
		printf("Press ESC to quit fdf.\nx/col:%d - y/line: %d\n", mlx->map->x_tab, mlx->map->y_tab);
		mlx->ptr = mlx_init();
		mlx->wdw = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "Hello fdf!");
		ft_draw_map(mlx, av[2][1]);
		mlx_key_hook(mlx->wdw, deal_key, mlx);
		mlx_loop(mlx->ptr);
	}
	else
		write(2, "Usage: ./fdf <file.fdf> -p/-i\n", 30);
	return 0;
}
