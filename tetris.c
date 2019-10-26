/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:19:38 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/26 19:10:28 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

t_etris	*create_tetris(char *str)
{
	t_etris *tetris;
	t_info	*info;

	info = create_info(str);
	if (!(tetris = (t_etris *)ft_memalloc(sizeof(t_etris))))
		return (NULL);
	tetris->coord = cool(info->block_count, info->output);
	tetris->value = value(info->output);
	free(info);
	return (tetris);
}
