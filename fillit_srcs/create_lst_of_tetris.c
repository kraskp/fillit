/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_of_tetris.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:30:52 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/03 16:33:14 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

/*
**changing a string of ., #, \n into a coordinates
*/

int		*intcoordinates(char *str)
{
	int		*coordinates;
	int		i;
	int		j;
	char	*new;

	new = spot(str);
	coordinates = (int *)malloc(sizeof(int) * 8);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (new[i] == '#')
		{
			coordinates[j] = i % 5;
			coordinates[j + 1] = i / 5;
			j += 2;
		}
		i++;
	}
	return (coordinates);
}

t_etris	*create_tetris(int *array, char c)
{
	t_etris	*tetris;

	if (!(tetris = (t_etris *)ft_memalloc(sizeof(t_etris))))
		return (NULL);
	tetris->coord = array;
	tetris->value = c;
	return (tetris);
}

t_etris	*create_lst(char **output)
{
	int		i;
	t_etris	*list;
	t_etris	*tetris;

	i = 0;
	list = create_tetris(intcoordinates(output[i]), 'A' + i);
	tetris = list;
	i++;
	while (output[i])
	{
		tetris->next = create_tetris(intcoordinates(output[i]), 'A' + i);
		tetris = tetris->next;
		i++;
	}
	tetris->next = NULL;
	return (list);
}
