/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_fx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:47:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/26 19:15:22 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

int		block_connection(char *str)
{
	int		block;
	int		i;

	block = 0;
	i = 0;
	while (i < 20)
	{
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

int		block_validator(char *block)
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
		// The following code will be necessary to prevent segfaults in the final version
		// I noticed this after testing some of the bad blocks files in the tests_blocks folder
		// ft_exit_error();
	}
	if (!(block[i] == 0 || block[i] == '\n'))
	{
		return (0);
		// The following code will be necessary to prevent segfaults in the final version
		// I noticed this after testing some of the bad blocks files in the tests_blocks folder
		// ft_exit_error();
	}
	if (sum != 732)
		return (0);
	return (1);
}

t_info		*check_num_blocks(int fd, t_info *info)
{
	char	*line;

	info->block_count = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		info->block_count++;
		free(line);
	}
	info->block_count++;
	// Added an extra check here.
	// If (number of lines + 1) % 5 does not = 0, then the input file is wrong.
	if (info->block_count % 5 != 0)
		ft_exit_error();
	info->block_count /= 5;
	return (info);
}
