/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:27:32 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 18:28:28 by kkraszew         ###   ########.fr       */
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

t_map	*create_map(t_info *info)
{
	t_map	*mapp;

	if (!(mapp = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	mapp->maxi = (ft_max(info->coord));
	mapp->mappi = starting_map(mapp->maxi);
	return (mapp);
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
