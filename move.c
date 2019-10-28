#include "./includes/lib_fillit.h"

void	move(t_list *lst, int y, int x)
{	
	int i;
	t_etris *t;

	t = lst->content;
	i = 0;
	while(lst)
	{
		t = lst->content;
		while (i < 8)
		{
			if (i % 2 == 0)
				ft_putnbr(t->coord[i] + x);
			else
				ft_putnbr(t->coord[i] + y);
			i++;
		}
		lst = lst->next;
		i = 0;
//		lst = lst->next;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	move_back_if_no_fit(t_etris *t, int x, int y)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			t->coord[i] = t->coord[i] - x;
		else
			t->coord[i] = t->coord[i] - y;
		i++;
	}
}

int	check_if_fits(t_map *map, t_etris *t, int x, int y)
{
	int i;

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
		if (map->maxi <= t->coord[i] || map->maxi <= t->coord[i + 1])
		{
			move_back_if_no_fit(t, x, y);
			return (0);
		}
		if (map->mappi[t->coord[i + 1]][t->coord[i]] == '.')
			i += 2;
		else
		{
			move_back_if_no_fit(t, x, y);
			return (0);
		}
	}
        return (1);
}

void	fill_map(t_map *map, t_etris *t)
{
	map->mappi[t->coord[1]][t->coord[0]] = t->value;
	map->mappi[t->coord[3]][t->coord[2]] = t->value;
	map->mappi[t->coord[5]][t->coord[4]] = t->value;
	map->mappi[t->coord[7]][t->coord[6]] = t->value;
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


void	solver(t_map *map, t_list *lst)
{
	int	i;
	int	j;

	t_etris	*t;
	t_list	*tmp;
	t_list	*head;
	ft_putnbr(map->maxi);
//	if (lst == NULL)
//		return 1;
	t = lst->content;
	j = -1;
	while (++j < map->maxi)
	{
		i = -1;
		while (++i < map->maxi)
		{
			if(check_if_fits(map, t, i, j))
			{
//				if(solver(map, lst->next))
//					return 1;
//				else
//				{
					fill_map(map,t);
//				ft_putstr("taalla");
				fill_map(map, t);
				lst = lst->next;
				t = lst->content;
//				printmap(map);
//				}
			}
		}
	}
//	return 0;
}
/*
t_map	*solve(t_list *list, t_map *map)
{
	while(!(solver(map, list)))
		bigger_map(map);
	return map;
}*/









