/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:19:38 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 17:34:30 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

t_etris	*create_tetris(int *array, char c)
{
	t_etris *tetris;

	if (!(tetris = (t_etris *)ft_memalloc(sizeof(t_etris))))
		return (NULL);
	tetris->coord = array;
	tetris->value = c;
	return (tetris);
}
