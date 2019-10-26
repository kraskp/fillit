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

t_map	*create_map(t_etris *tetris)
{
	t_map	*mapp;
	
	if (!(mapp = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	mapp->maxi = (ft_max(tetris->coord[0]));
	mapp->mappi = starting_map(mapp->maxi);
	return (mapp);
}
