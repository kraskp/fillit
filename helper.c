/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:45:55 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/26 19:17:28 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"

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
