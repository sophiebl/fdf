/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:55:09 by vimucchi          #+#    #+#             */
/*   Updated: 2019/02/26 14:01:23 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(void)
{
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_clear_window(mlx->ptr, mlx->wdw);
		exit(1);
	}
	return (0);
}

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
	t_mlx	mlx[1];
	t_img	img[1];

	if (ac == 3)
	{
		fd = ft_verif(av[1]);
		mlx->map = ft_get_tab(ft_get_map(fd));
		if (close(fd) == -1)
		{
			write(2, "Error: file can't be closed\n", 28);
			exit(1);
		}
		mlx->ptr = mlx_init();
		mlx->wdw = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT,
"Hello fdf!");
		img->img_ptr = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
		img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->s_l), &(img->endian));
		mlx->img = img;
		ft_draw_map(mlx, av[2][1]);
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, img->img_ptr, 0, 0);
		mlx_key_hook(mlx->wdw, deal_key, mlx);
		mlx_loop(mlx->ptr);
	}
	else
		write(2, "Usage: ./fdf <file.fdf> -p/-i\n", 30);
	return (0);
}
