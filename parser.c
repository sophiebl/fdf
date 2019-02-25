#include "fdf.h"

 t_line		*ft_get_map(int fd)
 {
 	int			i;
 	char 		*line;
 	t_line		*lst;
 	t_line		*begin;
 	int			nb_line;

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
 		lst->x_str = i;
 		lst->next = malloc(sizeof(t_line));
 		lst = lst->next;
 		free (line);
 	}
 	lst->next = NULL;
	begin->y_str = nb_line;
 	return (begin);
 }

t_parse		*ft_get_tab(t_line *line)
{
	t_parse		*map;
	t_line		*tmp;
	int			i;
	int			j;

	map = malloc(sizeof(t_parse));
	map->x_tab = line->x_str;
	map->y_tab = line->y_str;
	tmp = line;
	while (tmp->next)
	{
		if (map->x_tab != line->x_str)
		{
			write(2, "Error:\nThe file is invalid", 26);
			exit(1);
		}
		tmp = tmp->next;
	}
	if (!(map->tab = malloc(sizeof(int **) * map->y_tab)))
		return (0);
	j = 0;
	while (line->next)
	{
		map->tab[j] = malloc(sizeof(int *) * line->x_str);
		i = 0;
		while (i < line->x_str)
		{
			map->tab[j][i] = ft_atoi(line->str[i]);
			i++;
		}
		j++;
		line = line->next;
	}
	map->tab[j] = 0;
	printf("----Back to the main-----\n");
	return (map);
}
