#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	struct s_mlx	*next;
}					t_mlx;

typedef struct		s_line
{
	char			**str;
	int				nb_col;
	struct s_line	*next;
}					t_line;

t_line	*ft_get_map(int fd);
int		**ft_get_tab(t_line *lst);

#endif
