/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:35:43 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 12:04:07 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen((char *)s);
	while (length != 0 && s[length] != (char)c)
		length--;
	if (s[length] == (char)c)
		return ((char *)&s[length]);
	return (NULL);
}
