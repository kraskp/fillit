/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:45:55 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/03 16:01:36 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit_usage(void)
{
	ft_putstr("usage:\t./fillit source_file\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	free_lst(t_etris *lst)
{
	t_etris	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst->coord);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}

void	free_info(t_info *info)
{
	int		j;
	char	**output;

	j = -1;
	output = info->output;
	while (output[++j])
		free(output[j]);
	free(output);
	free(info);
	info = NULL;
	output = NULL;
}

void	free_mappi(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
