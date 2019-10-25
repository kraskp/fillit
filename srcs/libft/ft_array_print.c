/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:37:35 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 19:41:58 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_print(int *arr, size_t size, char *encl)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return ;
	if (ft_strlen(encl) != 2)
		encl = "{}";
	while (i < (size - 1))
	{
		ft_putchar(encl[0]);
		ft_putnbr(arr[i]);
		ft_putchar(encl[1]);
		ft_putstr(", ");
		i += 1;
	}
	ft_putchar(encl[0]);
	ft_putnbr(arr[i]);
	ft_putchar(encl[1]);
	ft_putstr("\n");
}
