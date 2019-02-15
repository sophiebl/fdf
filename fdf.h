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

# define WIN_WIDTH 1601
# define WIN_HEIGHT 801

typedef struct		s_img
{
	void		*img_ptr;
	char		*img_str;
	int		*data;
	int		bpp;
	int		s_l;
	int		endian;
}			t_img;

typedef struct		s_parse
{
	int		**tab;
	int		x_tab;
	int		y_tab;
}			t_parse;

typedef struct		s_mlx
{
	void		*ptr;
	void		*wdw;
	t_img		*img;
	t_parse		*map;
}			t_mlx;

typedef struct		s_line
{
	char		**str;
	int		x_str;
	int		y_str;
	struct s_line	*next;
}			t_line;


/*
 * parser.c
 *
*/

t_line 	*ft_get_map(int fd);
t_parse	*ft_get_tab(t_line *str);

/*
 * img.c
 *
*/

int	ft_draw_map(t_mlx *mlx, int gap, char c);
int	ft_line(t_mlx *mlx,int x1, int y1, int x2, int y2, int color);
void	get_img(t_mlx *mlx);
void	fill_pixel(t_img *img);

#endif
