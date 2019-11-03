/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfx_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:18:57 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/03 16:21:12 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*string;

	length = 0;
	while (s1[length])
		length++;
	if (!(string = (char*)malloc(sizeof(*string) * (length + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
