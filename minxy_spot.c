/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_value_spot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:07:03 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/30 16:21:01 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

int		*ft_min(char *str)
{
	int	*min;
	int	i;

	i = 0;
	min = (int *)malloc(sizeof(int) * 2);
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
	if (m == 0)
		return (str);
	while (i < 20)
	{
		if (str[i] == '#')
		{
			str[i - m] = '#';
			str[i] = '.';
		}
		i++;
	}
	free(min);
	return (str);
}
