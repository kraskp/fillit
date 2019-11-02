/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_fx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:47:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/02 17:09:33 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_fillit.h"

/*
**checking # neihbours has to be either 6 or 8
*/

int	block_connection(char *str)
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

int	block_validator(char *block)
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
*/

int	check_num_blocks(char *file)
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
