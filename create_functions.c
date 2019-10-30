/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:27:32 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/30 20:11:08 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

t_info	*create_info(char *str)
{
	t_info *info;

	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	info->block_count = check_num_blocks(str);
	info->output = input_strings(str, info->block_count);
	info->coord = cool(info->block_count, info->output);
	return (info);
}

int		*intcoordinates(char *str)
{
	int	*c;
	int	i;

	c = (int *)malloc(sizeof(i) * 8);
	i = 0;
	while (i < 8)
	{
		c[i] = str[i] - '0';
		i++;
	}
	return (c);
}

t_etris	*create_tetris(int *array, char c)
{
	t_etris	*tetris;

	if (!(tetris = (t_etris *)ft_memalloc(sizeof(t_etris))))
		return (NULL);
	tetris->coord = array;
	tetris->value = c;
	tetris->x_off = 0;
	tetris->y_off = 0;
	return (tetris);
}

t_etris	*create_lst(char **coords)
{
	int			i;
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
