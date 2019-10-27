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

int	check_if_fits(t_map *map, char *t, int x, int y)

{
	int	i;
	char	c;

	i = 0;
	ft_putstr(t);
	while (i < 8)
	{
		ft_putchar(t[i]);
		if (i % 2 == 0 && x != 0)
		{
			t[i] = t[i] + x;
			printf("%c", t[i]);
		}
		else if (i % 2 != 0 && y != 0)
			t[i] = t[i] + y;
		i++;
	}
	printf("here");
	i = 0;
	while (i <= 6)
	{
		if (map->mappi[t[i]][t[i + 1]] == '.')
			i += 2;
		else
			return (0);
	}
	return (1);
}	
