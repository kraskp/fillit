/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_value_spot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:07:03 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 18:14:01 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

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

int		*ft_min(char *str)
{
	int	*min;
	int	i;

	i = 0;
	min = ft_memalloc(8);
	min[0] = 3;
	min[1] = 3;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min[1])
				min[1] = i / 5;
			if (i % 5 < min[0])
				min[0] = i % 5;
		}
		i++;
	}
	return (min);
}

char	*spot(char *str)
{
	int	m;
	int	i;
	int	*min;

	if (str[0] == '#')
		return (str);
	min = ft_min(str);
	i = 0;
	m = min[0] + min[1] * 5;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			str[i - m] = '#';
			str[i] = '.';
		}
		i++;
	}
	return (str);
}
