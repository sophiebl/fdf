#include "fdf.h"

/*
 * creation de la liste contenant les lignes lues grace a GNL
 *
 *
 */
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
	while (get_next_line(fd, &line))
	{
		nb_line++;
		if (!(lst->str = ft_strsplit(line, ' ')))
			return 0;
		i = 0;
		while (lst->str[i])
			i++;
		lst->x_tab = i;
		lst->next = malloc(sizeof(t_line));
		lst = lst->next;
		free (line);
	}
	printf("line : lst->x_tab%d\n", lst->x_tab);
	lst->next = NULL;
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
	nb_col = lst->x_tab;
	tmp = lst;
	printf("line : lst->x_tab%d\n", lst->x_tab);
	while (tmp->next)
	{
		nb_line++;
		if (tmp->x_tab != lst->x_tab)
		{
			write(2, "Error:\nThe file is invalid", 26);
			exit(1);	
		}
		tmp = tmp->next;
	}
	tmp->y_tab = nb_line;
	if (!(tab = malloc(sizeof(int **) * nb_line)))
		return 0;
	j = 0;
	while (lst->next)
	{
		tab[j] = malloc(sizeof(int *) * lst->x_tab);
		i = 0;
		while (i < lst->x_tab)
		{
			tab[j][i] = ft_atoi(lst->str[i]);
			i++;
		}
		j++;
		lst = lst->next;
	}
	tab[j] = 0;
	j = 0;
	printf("line malloc: lst->x_tab%d\n", lst->x_tab);
	while (j < nb_line)
	{
		i  = 0;
		while (i < nb_col)
		{
			i++;
		}
		j++;
	}
	printf("line : nb_line%d\n", nb_line);
	printf("line : lst->x_tab%d\n", lst->x_tab);
	printf("line : nb_col%d\n", nb_col);
	printf("line : lst->y_tab%d\n", lst->y_tab);
	printf("----Back to the main-----\n");
	return (tab);
}
