/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:35:03 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 19:36:06 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_array_pop(int *arr, size_t size, unsigned int pos)
{
	if (size >= pos)
	{
		while (pos++ < size)
			arr[pos - 1] = arr[pos];
	}
	return (arr);
}
