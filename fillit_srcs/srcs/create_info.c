/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:27:32 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/31 17:24:27 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_fillit.h"

/*
**changing a string of ., #, \n into a coordinates
*/

char	*coordinates(char *str)
{
	char	*c;
	int		i;
	int		j;
	char	*new;

	new = spot(str);
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

/*
**making string of strings of tetrises
**(12xdots, 4x'\n', 4x#) x ammount of tetrises
**into a coordinates
*/

char	**cool(int block_count, char **output)
{
	char	**jou;
	int		i;

	i = -1;
	if (!(jou = (char **)malloc(sizeof(char *) * block_count + 1)))
		return (NULL);
	while (output[++i])
		jou[i] = coordinates(output[i]);
	jou[block_count] = NULL;
	return (jou);
}

/*
**chopping the content of a file to string of single tetris strings
**also validating the tetris pieces
*/

char	**input_strings(char *file, int size)
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
	fd = open(file, O_RDONLY);
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

/*
**taking a file parameter
**opening the file and storing
**ammount of tetris,
**content of a file (21 chars) x ammount of tetris ->(**str)
**content of a file as coordinates, 9 chars x ammount of tetris ->(**coord)
**0,0,0,1,1,0,1,1, means 2x2 square
**check_num_blocks & input_strings
*/

t_info	*create_info(char *file)
{
	t_info *info;

	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	info->block_count = check_num_blocks(file);
	if (!(info->output = input_strings(file, info->block_count)))
		ft_exit_error();
	info->coord = cool(info->block_count, info->output);
	return (info);
}
