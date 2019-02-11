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
	int		*data;
	int		bpp;
	int		s_l;
	int		endian;
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	t_img			img;
	struct s_mlx	*next;
}					t_mlx;

typedef struct		s_line
{
	char			**str;
	int				nb_col;
	struct s_line	*next;
}					t_line;

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

void	get_img(void	*mlx_ptr);
void	fill_pixel(char *img_str, int x, int y, int color);

#endif
