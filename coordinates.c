/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:30:52 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 17:09:36 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

int	*min(char *str)
{
	int *min;
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

char	*spot(char *str, char *min)
{
	int m;
	int i;

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

char	*coordinates (char *spot)
{
	char *c;
//	char *c;
	int i;
	int j;

	c = ft_memalloc(9);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (spot[i] == '#')
		{
			c[j] = i % 5;
			c[j + 1] = 1 / 5;
			j += 2;
		}
		i++;
	}
	c[8] = 0x00;
	return (c);
}
