#include "fdf.h"


int		ft_nb(t_line *lst)
{
	int 	nb_lines;
	t_line 	*new;

	nb_lines = 0;
	if (lst)
	{
		while (lst->next)
			nb_lines++;
		lst->next = new;
	}
}

int		*parser(fd)
{
	//	char 	*line;
	t_line 	lst;
	char	**str;
	int 	**tab;
	int 	i;
	int 	nb_line;
	int 	j;

	if (!(tab = (int **)malloc(sizeof(*tab) * i)))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &lst.line) == 1)	
	{
		nb_line++;
		if (!(str = ft_strsplit(lst.line, ' ')))
			return (NULL);
		printf("str[i] : %s\n", str[i]);
		j = 0;
		while (str[j])
		{
			if (!(tab[j] = (int *)malloc(sizeof(int) * 12055)))
				return (NULL);
			tab[i][j] = ft_atoi(str[j]);
			printf("tab[i][j] : %d\n", tab[i][j]);
			j++;
		}
		i++;
		free(&lst.line);
	}
	return (0);
}
