/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:08:09 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 20:09:25 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_array_copy(const int *src, int *dst, size_t n_src, size_t n_dst)
{
	unsigned	i;

	i = 0;
	while (i < n_src && i < n_dst)
	{
		dst[i] = src[i];
		i += 1;
	}
	return (dst);
}
