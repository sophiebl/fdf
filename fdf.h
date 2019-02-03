#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <fcntl.h>

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	struct s_mlx	*next;
}					t_mlx;

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

int		*parser(int fd);
int		ft_nb(t_line *lst);
#endif
