/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:30:52 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 16:35:06 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

char	*min(char *str)
{
	char *min;
	int	i;

	i = 0;
	min = "3,3";
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
	//	char c[9];
	char *c;
	int i;
	int j;

	c = NULL;
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
	return (c);
}
