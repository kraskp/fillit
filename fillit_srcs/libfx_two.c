/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfx_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:01:10 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/03 16:33:53 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != c)
	{
		if (!*p)
			return (NULL);
		p++;
	}
	return (p);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;

	s3 = NULL;
	if (s1 && s2)
	{
		s3 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) +
			ft_strlen(s2) + 1));
		if (!s3)
			return (NULL);
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}
