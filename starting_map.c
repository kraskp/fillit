/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:40:02 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 13:16:48 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"
#include <stdio.h>

char	**starting_map(int max)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * max + 1)))
		return (NULL);
	while (i < max)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * max + 1)))
			return (NULL);
		ft_memset(map[i], '.', max);
		map[i][max] = '\0';
		i++;
	}
	map[max] = NULL;
	return (map);
}

t_map	*bigger_map(t_map *map)
{
	map->maxi++;
	free(map->mappi);
	map->mappi = starting_map(map->maxi);
}
