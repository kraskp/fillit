/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:19:37 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/30 20:24:34 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

int		check_if_in_bounds(t_map *map, t_etris *t, char axis)
{
	if (axis == 'y')
	{
		return (t->coord[1] + t->y_off < map->maxi &&
			t->coord[3] + t->y_off < map->maxi &&
			t->coord[5] + t->y_off < map->maxi &&
			t->coord[7] + t->y_off < map->maxi);
	}
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
