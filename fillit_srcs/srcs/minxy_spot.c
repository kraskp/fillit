/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minxy_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:07:03 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/31 17:23:11 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_fillit.h"

/*
**to check how much the actual tetris is from a upper left corner
*/

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

/*
**moving # to uppler left corner as possible
*/

char	*spot(char *str)
{
	int	m;
	int	i;
	int	*min;

	min = ft_min(str);
	m = min[0] + min[1] * 5;
	if (m == 0)
	{
		free(min);
		min = NULL;
		return (str);
	}
	i = 0;
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
	min = NULL;
	return (str);
}