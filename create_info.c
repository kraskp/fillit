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

t_info	*create_info(char *str)
{
	t_info *info;

	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	info->block_count = check_num_blocks(str);
	info->output = input_strings(str, info->block_count);
//	info->coord = cool(info->block_count, info->output);
	return (info);
}
