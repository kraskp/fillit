/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/30 20:37:12 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/libft/includes/libft.h"
#include "./includes/lib_fillit.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	*info;
	t_etris	*lst;
	t_map	*map;
	t_etris *head;

	info = NULL;
	lst = NULL;
	map = NULL;
	head = NULL;
	i = 0;
	if (argc != 2)
		ft_exit_usage();
	if (argc == 2)
	{
		info = create_info(argv[1]);
		lst = create_lst(info->coord);
		head = lst;
		map = create_map(info);
	}
	map = solve(lst, map);
	printmap(map);
	free_mappi(map->mappi);
	main_help(map, head, info);
	return (0);
}
