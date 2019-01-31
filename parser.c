#include "fdf.h"

t_line	*ft_get_map(int fd)
{
	int		i;
	char 	*line;
	t_line	*lst;
	t_line	*begin;
	int		nb_line;

	if (!(lst = malloc(sizeof(t_line))))
		return 0;
	begin = lst;
	nb_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		nb_line++;
		if (!(lst->str = ft_strsplit(line, ' ')))
			return 0;
	   	i = 0;
		while (lst->str[i])
		{
			lst->nb_col++;
			i++;
		}
		lst->next = malloc(sizeof(t_line));
		lst = lst->next;
		free (line);
	}
	lst->next = NULL;
	return (begin);
}

int		**ft_get_tab(t_line *lst)
{
	t_line 	*tmp;
	int		nb_line;
	int		i;
	int		j;
	int		**tab;

	nb_line = -1;
	tmp = lst;
	while (tmp)
	{
		nb_line++;
		tmp = tmp->next;
	}
	printf("nb_line:%d\n", nb_line);
	if (!(tab = malloc(sizeof(int **) * nb_line)))
		return 0;
	j = 0;
	while (lst->next)
	{
		printf("nb_col:%d\n", lst->nb_col);
		tab[j] = malloc(sizeof(int *) * lst->nb_col);
		i = 0;
		while (i < lst->nb_col)
		{
			tab[j][i] = ft_atoi(lst->str[i]);
			i++;
		}
		j++;
		lst = lst->next;
	}
	j = 0;
	while (tab[j])
	{
		i  = 0;
		while(tab[j][i])
		{
			printf("%d", tab[j][i]);
			i++;
		}
		j++;
		ft_putchar('\n');
	}
	return (tab);
}
