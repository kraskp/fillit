/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:16:31 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 11:53:33 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dp;
	unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (src == dst)
		return (dst);
	else if (src > dst)
		ft_memcpy(dp, sp, len);
	else
		while (len--)
			dp[len] = sp[len];
	return (dst);
}
