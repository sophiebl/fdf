/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:55:09 by vimucchi          #+#    #+#             */
/*   Updated: 2019/02/26 19:02:06 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(void)
{
}
/*
t_space		ft_new_space(int x, int y, int z, float incr)
{
	t_space new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.incr = incr;
	return (new);
}
*/
int			deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_clear_window(mlx->ptr, mlx->wdw);
		exit(1);
	}
	return (0);
}
/*
static int	zoom_key(int key, t_mlx *mlx)
{
	static int	cmp = 0;
	t_space		add;
	if (key == 38 || key == 69 || key == 24)
	{
		cmp++;
		add = ft_new_space(0, 0, 0, 2.0);
		printf("%d", mlx->zoom.gap_x);
		mlx->zoom.gap_x *= 2;
		printf("%d", mlx->zoom.gap_x);
		mlx->zoom.gap_y *= 2;
		mlx->zoom.gap_z *= 2;
		ft_draw_map(mlx, 'c');
	}
	if (key == 40 || key == 27 || key == 78)
	{
		cmp++;
		add = ft_new_space(0, 0, 0, -2.0);
		mlx->zoom.gap_x /= 2;
		mlx->zoom.gap_y /= 2;
		mlx->zoom.gap_z /= 2;
		ft_draw_map(mlx, 'c');
	}
	return (0);
}
*/
int			ft_verif(char *file)
{
	int		i;
	int		fd;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
	{
		write(2, "Error: Usage: ./fdf <file.fdf> -p/-i\n", 36);
		exit(1);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(2, "Error: file doesn't exist\n", 26);
		exit(1);
	}
	return (fd);
}

int			main(int ac, char **av)
{
	int		fd;
	t_mlx	mlx;

	if (ac == 3)
	{
		fd = ft_verif(av[1]);
		ft_get_tab(ft_get_map(fd), &mlx.map);
		if (close(fd) == -1)
		{
			write(2, "Error: file can't be closed\n", 28);
			exit(1);
		}
		mlx.ptr = mlx_init();
		mlx.wdw = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT,
				"Hello fdf!");
		ft_draw_map(&mlx, av[2][1]);
		mlx_key_hook(mlx.wdw, deal_key, &mlx);
//		mlx_key_hook(mlx.wdw, zoom_key, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		write(2, "Usage: ./fdf <file.fdf> -p/-i\n", 30);
	return (0);
}
