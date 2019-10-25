/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_fx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:47:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 16:47:51 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

int	block_connection(char *str)
{
	int	block;
	int	i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i + 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) < 20 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8); //or maybe block number bc 8 means 2x2
}

int	block_validator(char *block)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < 20)
	{
		sum += block[i];
		i++;
		if (i % 5 == 0 && block[i - 1] != 'n')
			return (1);
	}
	if (!(block[i] == 0 || block[i] == '\n'))
		return (2);
	if (sum != 732)
		return (3);
	return (0);
}

// count of blocks will be done by get nextd line / 5

			
int	check_num_blocks(int fd, char **file)
{
	int	block_count;
	char	*line;

	block_count = 0;
	line = NULL;
	
	fd = open(file[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		block_count++;
		free(line);
	}
	block_count++;
	block_count /= 5;
	return (block_count);
}