/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 19:16:40 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/libft/includes/libft.h"
#include "./includes/lib_fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	block_count;
	char **output;
	int i;
	char **coord;
	char *encl;
	char **map;

	encl = "{}";
	i = 0;
	fd = 0;
	block_count = 0;
	output = NULL;
	if (argc != 2)
		ft_putstr("usage:\t./fillit source_file\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		block_count = check_num_blocks(fd, argv[1]);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		output = input_strings(argv[1], block_count);
		close(fd);
	}
	if (!(coord = (char **)ft_memalloc(sizeof(char *) * (block_count + 1))))
		printf("error");
	coord[block_count] = '\0';
	while (output[i])
	{
		coord[i] = coordinates(output[i], i);
		printf("%s\n", coord[i]);
		i++;
	}
	printf("%d\n", max(coord[0]));
	map = startingMap(max(coord[0]));

//		m = min(output[i]);
//		ft_array_print(m, 2, encl);
//		ft_putchar('\n');
//		i++;
//	}
//	if (fd == -1)
//	{
//		ft_putstr("error\n");
//		exit(EXIT_FAILURE);
//	}
//	while (output[i])
//	{
//		if (!block_connection(output[i]) && !block_validator(output[i])) 
//		{
//			printf("%s", output[i]);
//			ft_putnbr(i);
//			ft_putchar('\n');
//		}
//			i++;
//	}
	//ft_putnbr(block_count);
	//	ft_putstr(*output);
	return (0);
}
