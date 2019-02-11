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
	int 	**tab;
	t_mlx	mlx;

	if (ac >= 2 && ac <= 4)
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
		tab = ft_get_tab(ft_get_map(fd));
		if (close(fd) == -1)
		{
			write(2, "Error:\nfile can't be closed", 27);
			exit(1);
		}
		mlx.ptr = mlx_init();
		get_img(mlx_ptr);
	}
	return 0;
}
