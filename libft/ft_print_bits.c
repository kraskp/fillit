/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:57:05 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 14:31:18 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	unsigned char	bit;

	bit = (octet >> 7 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 6 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 5 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 4 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 3 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 2 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 1 & 1) + '0';
	ft_putchar(bit);
	bit = (octet >> 0 & 1) + '0';
	ft_putchar(bit);
}
