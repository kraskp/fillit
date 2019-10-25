/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_max_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:50:53 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 20:07:22 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_max_value(int *arr, int length)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < length)
	{
		if (max < arr[i])
			max = arr[i];
		i += 1;
	}
	return (max);
}
