/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:42:38 by vtran             #+#    #+#             */
/*   Updated: 2019/11/03 16:01:49 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**checking that a tetris do not over lap with other tetrises
**starting from a given coordinates
**for this reason we have putted all tetris coordinates
**to start from upper left corner as possible
*/

int		overlap(t_map *map, t_etris *t, int j, int i)
{
	int k;
	int x;
	int y;

	k = 0;
	x = t->coord[k] + i;
	y = t->coord[k + 1] + j;
	while (k <= 6 && map->mappi[y][x] == '.')
	{
		k += 2;
		x = t->coord[k] + i;
		y = t->coord[k + 1] + j;
	}
	return (k != 8);
}

/*
**checking if given tetris is fitting in a map
**1,3,5,7 is y axis for a tetris, z is y or x index in a map
*/

int		check_if_in_bounds(t_map *map, t_etris *t, char axis, int z)
{
	int	over_bounds;

	over_bounds = map->maxi;
	if (axis == 'y')
		return (t->coord[1] + z < over_bounds &&
				t->coord[3] + z < over_bounds &&
				t->coord[5] + z < over_bounds &&
				t->coord[7] + z < over_bounds);
	else
		return (t->coord[0] + z < map->maxi &&
				t->coord[2] + z < over_bounds &&
				t->coord[4] + z < over_bounds &&
				t->coord[6] + z < over_bounds);
}

/*
**if no overlap and in_bounds
*/

void	fill_map(t_map *map, t_etris *t, char value, int *yx)
{
	map->mappi[t->coord[1] + yx[0]][t->coord[0] + yx[1]] = value;
	map->mappi[t->coord[3] + yx[0]][t->coord[2] + yx[1]] = value;
	map->mappi[t->coord[5] + yx[0]][t->coord[4] + yx[1]] = value;
	map->mappi[t->coord[7] + yx[0]][t->coord[6] + yx[1]] = value;
}

/*
**actual magic. here will check linked list tetris
**and put them into a map. backtracking with recursive calls
**bruteforce until no lst or will make a bigger square
**if no fit with all the order possibilities
*/

int		solver(t_map *map, t_etris *t)
{
	int	yx[2];

	if (!t)
		return (1);
	yx[0] = 0;
	while (check_if_in_bounds(map, t, 'y', yx[0]))
	{
		yx[1] = 0;
		while (check_if_in_bounds(map, t, 'x', yx[1]))
		{
			if (!overlap(map, t, yx[0], yx[1]))
			{
				fill_map(map, t, t->value, yx);
				if (solver(map, t->next))
					return (1);
				else
					fill_map(map, t, '.', yx);
			}
			yx[1]++;
		}
		yx[0]++;
	}
	return (0);
}

/*
**call solver and make bigger map if no solution
*/

t_map	*solve(t_etris *list, t_map *map)
{
	while (!(solver(map, list)))
		map = bigger_map(map);
	return (map);
}
