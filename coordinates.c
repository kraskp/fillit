/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:30:52 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 18:16:23 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"
#include <stdio.h>

char	*coordinates(char *str)
{
	char		*c;
	int		i;
	int		j;
	char		*new;

	new = spot(&str[0]);
	c = ft_memalloc(9);
	i = 0;
	j = 0;
	while (i < 20)
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

char	**cool(int block_count, char **output)
{
	char	**jou;
	int		i;

	i = 0;
	if (!(jou = (char **)malloc(sizeof(char *) * block_count + 1)))
		return (NULL);
	while (output[i])
	{
		jou[i] = coordinates(output[i]);
		i++;
	}
	jou[block_count] = NULL;
	return (jou);
}

int		*intcoordinates(char *str)
{
	int		*c;
	int		i;

	c = (int *)malloc(sizeof(i) * 8);
	i = 0;
	while (i < 8)
	{
		c[i] = str[i] - '0';
		i++;
	}
	return (c);
}
t_etris	*create_lst(char **coords)
{
	int		i;
	t_etris		*list;
	t_etris		*tetris;

	i = 0;
	list = create_tetris(intcoordinates(coords[i]), 'A' + i);
	tetris = list;
	i++;
	while (coords[i])
	{
		tetris->next = create_tetris(intcoordinates(coords[i]), 'A' + i);
		tetris = tetris->next;
		i++;
	}
	tetris->next = NULL;
	return (list);
}
