/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:21:59 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/23 19:22:28 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddnext(t_list *lst, t_list *elm)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = elm;
}
