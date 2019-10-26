/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/26 19:13:10 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/libft/includes/libft.h"
#include "./includes/lib_fillit.h"
#include <stdio.h>

// usage of struct t_place *info has reduced number of variables needed here -KK
int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*encl;
	t_info	*info;

	info = NULL;
	encl = "{}";
	i = 0;
	fd = 0;
	if (argc != 2)
		ft_exit_usage();
	if (argc == 2)
	{
		info = create_info();
		fd = open(argv[1], O_RDONLY);
		info = check_num_blocks(fd, info);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		info->output = input_strings(argv[1], info->block_count);
		close(fd);
	}
	if (!(info->coord = (char **)ft_memalloc(sizeof(char *) *
		(info->block_count + 1))))
		info->coord = NULL;
	info->coord[info->block_count] = NULL;
	while (info->output[i])
	{
		info->coord[i] = coordinates(info->output[i], i);
		ft_putstr(info->coord[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putnbr(max(info->coord[0]));
	ft_putstr("\n");
	info = starting_map(max(info->coord[0]), info);
	ft_putnbr(max(info->coord[0]));
	ft_putstr("\n");
	ft_putnbr(info->block_count);
	ft_putstr("\n");

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
	free(info);
	return (0);
}
