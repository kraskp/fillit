/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:27:32 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/30 16:21:18 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

char	*coordinates(char *str)
{
	char	*c;
	int		i;
	int		j;
	char	*new;

	new = spot(&str[0]);
	c = ft_memalloc(9);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (new[i] == '#')
		{
			c[j] = i % 5 + '0';
			c[j + 1] = i / 5 + '0';
			j += 2;
		}
		i++;
	}
	c[8] = 0x00;
	return (c);
}

char	**cool(int block_count, char **output)
{
	char	**jou;
	int		i;

	i = 0;
	if (!(jou = (char **)malloc(sizeof(char *) * block_count + 1)))
		return (NULL);
	while (output[i])
	{
		jou[i] = coordinates(output[i]);
		i++;
	}
	jou[block_count] = NULL;
	return (jou);
}

char	**input_strings(char *path, int size)
{
	int		fd;
	int		ret;
	int		b;
	char	*buf;
	char	**output;

	b = -1;
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
			return (NULL);
		output[++b] = ft_strdup(buf);
	}
	output[size] = 0;
	free(buf);
	if (close(fd) == -1)
		output = NULL;
	return (output);
}

void	free_info(t_info *info)
{
	int i;
	int j;
	char	**co;
	char	**out;

	i = 0;
	j = 0;
	co = info->coord;
	out = info->output;
	while (co[i])
	{
		free(co[i]);
		i++;
	}
	while (out[j])
	{
		free(out[j]);
		j++;
	}
	free(co);
	free(out);
	free(info);
}

t_info	*create_info(char *str)
{
	t_info *info;

	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	info->block_count = check_num_blocks(str);
	if (!(info->output = input_strings(str, info->block_count)))
		ft_exit_error();
	info->coord = cool(info->block_count, info->output);
	return (info);
}
