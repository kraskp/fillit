/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 14:43:36 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

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
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buf, 21)))
	{
		output[b] = ft_strdup(buf);
		b++;
	}
	free(buf);
	if (close(fd) == -1)
		return (NULL);
	return (output);
}
			
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

int	main(int argc, char **argv)
{
	int	fd;
	int	block_count;
	char **output;
	int i;

	i = 0;
	fd = 0;
	block_count = 0;
	output = NULL;
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit source_file\n");
	}
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	else if (fd > 0)
	{
		block_count = check_num_blocks(fd, argv);
		output = input_strings(argv[1], block_count);
	}
	close(fd);

	ft_putnbr(block_count);
	//	ft_putstr(*output);
	return (0);
}
