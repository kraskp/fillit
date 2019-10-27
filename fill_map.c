#include "./includes/lib_fillit.h"

t_map	*fill_map(t_map *map, t_etris *t, int x, int y)
{
	int	i;
	
//	ft_putchar(t->value);
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			t->coord[i] = t->coord[i] + x;
		else
			t->coord[i] = t->coord[i] + y;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		map->mappi[t->coord[i]][t->coord[i+1]] = (char)t->value;
		i += 2;
	}
	return (map);
}	
