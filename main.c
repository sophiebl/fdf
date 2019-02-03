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
//	int		i;
//	int		j;
	int 	**tab;

//	i = 2;
//	j = 0;
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
		/*
		while (i < 20)
		{
			while (j < 5)
			{
				printf("tab  : %d, i : %d, j : %d", tab[i][j], i, j);
				j++;
			}
			i++;
		}*/
	}
	return 0;
}
