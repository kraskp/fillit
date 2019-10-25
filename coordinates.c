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

int	*ft_min(char *str)
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

char	*spot(char *str)
{
	int m;
	int i;
	int *min;
	
	if (str[0] == '#')
	{
		printf("%s", str);
		return (str);
	}
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
	printf("%s", str);
	return (str);
}

char	*coordinates (char *str)
{
	char *c;
//	char *c;
	int i;
	int j;
	char *new;

	new = spot(&str[0]);
	c = ft_memalloc(9);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (new[i] == '#')
		{
			c[j] = i % 5 + '0';
			c[j + 1] = i / 5 + '0';
			j += 2;
		}
		i++;
	}
	c[8] = 0x00;
	return (c);
}
