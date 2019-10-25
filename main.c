/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 16:49:55 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft/includes/libft.h"
#include "./includes/lib_fillit.h"

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
