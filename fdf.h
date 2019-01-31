#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	struct s_mlx	*next;
}					t_mlx;
