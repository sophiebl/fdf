#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	int 	**tab;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tab = ft_get_tab(ft_get_map(fd));
		n_window();
	}
	return 0;
}
