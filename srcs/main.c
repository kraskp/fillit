/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/31 17:23:09 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/lib_fillit.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_etris	*lst;
	t_map	*map;

	map = NULL;
	info = NULL;
	lst = NULL;
	if (argc != 2)
		ft_exit_usage();
	if (argc == 2)
	{
		info = create_info(argv[1]);
		lst = create_lst(info->coord);
		map = create_map(info);
		free_info(info);
	}
	map = solve(lst, map);
	printmap(map);
	free_mappi(map->mappi);
	free(map);
	free_lst(lst);
	return (0);
}
