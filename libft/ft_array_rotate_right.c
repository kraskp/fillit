/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_rotate_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:19:42 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 11:21:50 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_array_rotate_right(int *arr, size_t size, unsigned int tms)
{
	int				first;
	unsigned int	i;

	if (!tms || !arr)
		return (arr);
	first = arr[size - 1];
	i = size;
	while (tms > size)
		tms -= size;
	while (i)
	{
		arr[i] = arr[i - 1];
		i -= 1;
	}
	arr[i] = first;
	tms -= 1;
	if (tms)
		ft_array_rotate_right(arr, size, tms);
	return (arr);
}
