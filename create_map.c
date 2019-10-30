/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:40:02 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/30 11:01:54 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

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

int		ft_max(char **coord)
{
	int	i;
	int	min;
	int	j;

	j = 0;
	i = 2;
	while (coord[j])
		j++;
	min = j * 4;
	while (i * i < min)
		i++;
	return (i);
}

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

void	free_mappi(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{	
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

t_map	*bigger_map(t_map *map)
{
	map->maxi++;
	free_mappi(map->mappi);
	map->mappi = starting_map(map->maxi);
	return (map);
}

t_map	*create_map(t_info *info)
{
	t_map	*mapp;

	if (!(mapp = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	mapp->maxi = (ft_max(info->coord));
	mapp->mappi = starting_map(mapp->maxi);
	return (mapp);
}
