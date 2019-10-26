/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:40:02 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/26 16:40:06 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"
#include <stdio.h>

t_info	*starting_map(int max, t_info *info)
{
	char **map;
	int i;
	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * max + 1)))
		return (NULL);	
	while (i < max)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * max + 1)))
			return (NULL);
		ft_memset(map[i], 46, max);
		map[i][max] = '\0';
		printf("%s\n", map[i]);
		i++;
	}
	map[max] = NULL;
	info->map = map;
	return (info);
}