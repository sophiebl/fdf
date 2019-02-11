#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef struct		s_img
{
	void	*img_ptr;
	char	*img_str;
	int		*data;
	int		bpp;
	int		s_l;
	int		endian;
}					t_img;

typedef struct		s_line
{
	char			**str;
	int				x_tab;
	int				y_tab;
	struct s_line	*next;
}					t_line;

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	t_img			*img;
	t_line			*lst;
}					t_mlx;

/*
 * parser.c
 *
*/

t_line	*ft_get_map(int fd);
int		**ft_get_tab(t_line *lst);

/*
 * img.c
 *
*/

void	get_img(t_mlx *mlx);
void	fill_pixel(t_img *img);

#endif
