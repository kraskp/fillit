/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:16:25 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 11:52:19 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	i = 0;
	dp = (unsigned char*)dst;
	sp = (unsigned char*)src;
	while (i < n)
	{
		dp[i] = sp[i];
		if (dp[i] == (unsigned char)c || sp[i] == (unsigned char)c)
			return (dst + (++i));
		i++;
	}
	return (NULL);
}
