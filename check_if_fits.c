/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_fits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <heikki-seta@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:30:50 by vtran             #+#    #+#             */
/*   Updated: 2019/10/27 14:55:06 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

void	move_back_if_no_fit(t_etris  *t, int x, int y)
{
	int	i;

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

int	check_if_fits(t_map *map, t_etris  *t, int x, int y)
{
	int	i;

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
		if (map->mappi[t->coord[i]][t->coord[i + 1]] == '.')
			i += 2;
		else
		{
			move_back_if_no_fit(t, x, y);
			return (0);
		}
	}
	return (1);
}
