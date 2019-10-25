/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:26:00 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 12:03:48 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	x;

	x = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n-- >= x)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, x) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
