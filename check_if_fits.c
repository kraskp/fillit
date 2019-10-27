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
	i = -1;
	while (++i < 8)
		ft_putnbr(t->coord[i]);
	ft_putchar('\n');
	ft_putnbr(map->maxi);
	ft_putchar('\n');
	i = 0;
	while (i < 8)
	{
		if (map->maxi <= t->coord[i] || map->maxi <= t->coord[i + 1])
			return (0);
		if (map->mappi[t->coord[i]][t->coord[i + 1]] == '.')
				i += 2;
		else
			return (0);
	}
	return (1);
}	
