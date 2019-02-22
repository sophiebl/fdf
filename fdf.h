#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct		s_line
{
	char			**str;
	int				x_str;
	int				y_str;
	struct s_line	*next;
}					t_line;

typedef struct		s_color
{
	int				int_color;
	int				int_color2;
	unsigned int	a;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

typedef struct		s_parse
{
	int				**tab;
	int				x_tab;
	int				y_tab;
}					t_parse;

typedef struct		s_img
{
	void			*img_ptr;
	char			*img_str;
	int				*data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	t_img			*img;
	t_parse			*map;
	t_color			*color;
}					t_mlx;

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
}					t_coord;

t_line 				*ft_get_map(int fd);
t_parse				*ft_get_tab(t_line *str);

void				ft_proj_iso(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2);
void				ft_proj_p(t_mlx *mlx, int x1, int y1, int z1, int x2, int y2, int z2);

void				ft_draw_map(t_mlx *mlx, char c);
void				ft_line(t_mlx *mlx, t_coord *p, int color);

//void				get_img(t_mlx *mlx, t_coord *p, int color);
void				get_img(t_mlx *mlx, t_coord *p, t_color *color);
//void				fill_pixel(t_img *img, int x, int y, int color);
//void				fill_pixel(t_img *img, int color);
unsigned int			to_rgb(unsigned int a, unsigned int r,
					unsigned int g, unsigned int b);

#endif
