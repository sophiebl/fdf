#include "fdf.h"

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

	if (ac >= 2)
	{
		if (ft_verif(av[1]))
		{
			write(2, "Error:\nUsage: ./fdf <file.fdf>", 29);
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
		printf("%d\n", mlx->map->x_tab);
		printf("%d\n", mlx->map->y_tab);
		mlx->ptr = mlx_init();
		mlx->wdw = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "Window");
		get_img(mlx);
		ft_line(mlx, ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		mlx_loop(mlx->ptr);
	}
	return 0;
}
