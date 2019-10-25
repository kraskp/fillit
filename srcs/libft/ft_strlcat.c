/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:38:05 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 11:55:38 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	len = 0;
	while (dst[len] && len < dstsize)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < dstsize)
	{
		dst[len] = src[len - i];
		len += 1;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
