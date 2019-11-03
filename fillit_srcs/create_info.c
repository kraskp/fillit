/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:27:32 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/03 16:31:47 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**checking # neihgbours has to be either 6 or 8 and that
**there is no other chars than #, ., \n.
*/

int			block_connection(char *str)
{
	int		block;
	int		i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			ft_exit_error();
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

/*
**checking that every 5th char is \n
**checking that last one is '\n' or NULL
**checking that there is 12xdots, 4x# and 4x'\n'
*/

int			block_validator(char *block)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < 20)
	{
		sum += block[i];
		i++;
		if (i % 5 == 0 && block[i - 1] != '\n')
			return (0);
	}
	if (!(block[i] == 0 || block[i] == '\n'))
		return (0);
	if (sum != 732)
		return (0);
	return (1);
}

/*
**counting ammount of tetris blocks
**and checking that there is no more than 26 or less than 1 blocks
*/

int			check_num_blocks(char *file)
{
	char	*line;
	int		fd;
	int		block_count;

	block_count = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		block_count++;
		free(line);
	}
	block_count++;
	if (block_count % 5 != 0)
		ft_exit_error();
	block_count /= 5;
	close(fd);
	if (block_count > 26 || block_count < 0)
		ft_exit_error();
	return (block_count);
}

char		**input_strings(char *file, int size)
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

t_info		*create_info(char *file)
{
	t_info *info;

	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	info->block_count = check_num_blocks(file);
	if (!(info->output = input_strings(file, info->block_count)))
		ft_exit_error();
	return (info);
}
