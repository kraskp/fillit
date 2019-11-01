/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:30:34 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 19:33:17 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_array_new(size_t size)
{
	int	*arr;

	if (!(arr = (int *)ft_memalloc(sizeof(int) * size)))
		return (0);
	while (size)
		arr[size--] = 0;
	return (arr);
}
