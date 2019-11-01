/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_rotate_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:14:28 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 11:24:38 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_array_rotate_left(int *arr, size_t size, unsigned int tms)
{
	int				last;
	unsigned int	i;

	if (!tms || !arr)
		return (arr);
	last = arr[0];
	i = 0;
	while (tms > size)
		tms -= size;
	while (i < (size - 1))
	{
		arr[i] = arr[i + 1];
		i += 1;
	}
	arr[size - 1] = last;
	tms -= 1;
	if (tms)
		ft_array_rotate_left(arr, size, tms);
	return (arr);
}
