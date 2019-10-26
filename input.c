/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:15:11 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 19:30:42 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

char	**input_strings(char *path, int size)
{
	int		fd;
	int		ret;
	int		b;
	char	*buf;
	char	**output;

	b = 0;
	buf = ft_strnew(21);
	if (!(output = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		output = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		output = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = 0;
		if (!block_connection(buf) || !block_validator(buf))
			return (NULL); //also exit code;
		output[b] = ft_strdup(buf);
		b++;
	}
	output[size] = 0;
	free(buf);
	if (close(fd) == -1)
		output = NULL;
	return (output);
}
