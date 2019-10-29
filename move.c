#include "./includes/lib_fillit.h"

int	overlap(t_map *map, t_etris *t)
{
	int i;
	int x;
	int y;

	i = 0;
	x = t->coord[i] + t->x_off;
	y = t->coord[i + 1] + t->y_off;
	while (i <= 6 && map->mappi[y][x] == '.')
	{
		i += 2;
		x = t->coord[i] + t->x_off;
		y = t->coord[i + 1] + t->y_off;
	}
	return (i != 8);
}

int	check_if_in_bounds(t_map *map, t_etris *t, char axis)
{
	if (axis == 'y')
		return (t->coord[1] + t->y_off < map->maxi &&
			t->coord[3] + t->y_off < map->maxi &&
			t->coord[5] + t->y_off < map->maxi &&
			t->coord[7] + t->y_off < map->maxi);
	return (t->coord[0] + t->x_off < map->maxi &&
		t->coord[2] + t->x_off < map->maxi &&
		t->coord[4] + t->x_off < map->maxi &&
		t->coord[6] + t->x_off < map->maxi);
}

void	fill_map(t_map *map, t_etris *t, char value)
{
	map->mappi[t->coord[1] + t->y_off][t->coord[0] + t->x_off] = value;
	map->mappi[t->coord[3] + t->y_off][t->coord[2] + t->x_off] = value;
	map->mappi[t->coord[5] + t->y_off][t->coord[4] + t->x_off] = value;
	map->mappi[t->coord[7] + t->y_off][t->coord[6] + t->x_off] = value;
}

void	printmap(t_map *map)
{
	int i;

	i = 0;
	while (i < map->maxi)
	{
		ft_putstr(map->mappi[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}


int	solver(t_map *map, t_etris *t)
{
	if (!t)
		return (1);
	t->y_off = 0;
	while (check_if_in_bounds(map, t, 'y'))
	{
		t->x_off = 0;
		while(check_if_in_bounds(map, t, 'x'))
		{
			if (!overlap(map, t))
			{
				fill_map(map, t, t->value);
				if(solver(map, t->next))
					return (1);
				else
					fill_map(map,t, '.');
			}
			t->x_off++;
		}
		t->y_off++;
	}
	return (0);
}

t_map	*solve(t_etris *list, t_map *map)
{
	while(!(solver(map, list)))
		map = bigger_map(map);
	return map;
}
