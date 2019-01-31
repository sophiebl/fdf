#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
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
#endif
