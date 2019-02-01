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
			i++;
		lst->nb_col = i;
		lst->next = malloc(sizeof(t_line));
		lst = lst->next;
		free (line);
	}
	lst->next = NULL;
	printf("----End GNL-----\n");
	return (begin);
}

int		**ft_get_tab(t_line *lst)
{
	t_line 	*tmp;
	int		nb_line;
	int		nb_col;
	int		i;
	int		j;
	int		**tab;

	nb_line = 0;
	nb_col = lst->nb_col;
	tmp = lst;
	while (tmp->next)
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
		printf("\nnb_col:%d ", lst->nb_col);
		tab[j] = malloc(sizeof(int *) * lst->nb_col);
		i = 0;
		while (i < lst->nb_col)
		{
			tab[j][i] = ft_atoi(lst->str[i]);
			printf("%d ", tab[j][i]);
			i++;
		}
		j++;
		lst = lst->next;
	}
	printf("\n----End lst to tab-----\n");
	j = 0;
	printf("nb_col:%d, nb_line:%d\n",nb_col, nb_line);
	while (j < nb_col)
	{
		i  = 0;
		while(i < nb_line)
		{
			printf("%d ", tab[j][i]);
			i++;
		}
		j++;
		printf("- Line %d\n", j);
	}
	printf("----Back to the main-----\n");
	return (tab);
}
