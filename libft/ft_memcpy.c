/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:34:14 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 11:51:43 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;

	dp = (unsigned char*)dst;
	sp = (unsigned char*)src;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*dp++ = *sp++;
	return (dst);
}
