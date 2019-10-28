/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:30:52 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 18:16:23 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_fillit.h"
#include <stdio.h>

char	*coordinates(char *str)
{
	char	*c;
	int		i;
	int		j;
	char	*new;
	
//	ft_putstr(str);
//	ft_putstr("\n");
	new = spot(&str[0]);
//	ft_putstr("taalla");
//	ft_putstr("\n");
//	ft_putstr(new);
//	ft_putstr("\n");
	c = ft_memalloc(9);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (new[i] == '#')
		{
			c[j] = i % 5 + '0';
			c[j + 1] = i / 5 + '0';
			j += 2;
		}
		i++;
	}
	c[8] = 0x00;
//	ft_putstr(c);
//	ft_putstr("\n");
	return (c);
}

char	**cool(int block_count, char **output)
{
	char	**jou;
	int		i;

	i = 0;
	if (!(jou = (char **)malloc(sizeof(char *) * block_count + 1)))
		return (NULL);
	while (output[i])
	{
		jou[i] = coordinates(output[i]);
		i++;
	}
	jou[block_count] = NULL;
	return (jou);
}

int		*intcoordinates(char *str)
{
	int		*c;
	int		i;

//	ft_putstr(str);
//	ft_putstr("\n");
//	ft_putstr("\n");
	c = (int *)malloc(sizeof(int) * 8);
	i = 0;
	while (i < 8)
	{
		c[i] = str[i] - '0';
		i++;
	}
	return (c);
}

t_list	*create_lst(char **coords)
{
	int		i;
	t_list	*list;
	t_etris	*tetris;
	t_list	*head;
//	char	c;
//	int	*jou;
//	t_etris *makak;

//	c = 'A';
	i = 0;
//	jou = intcoordinates(output[i]);
	tetris = create_tetris(intcoordinates(coords[i]), 'A' + i);
//	ft_putchar(tetris->value);
	list = ft_lstnew(tetris, 50);
//	makak = list->content;
//	ft_putchar(makak->value);
	head = list;
	i++;
	while (coords[i])
	{
//		jou = intcoordinates(output[i]);
		tetris = create_tetris(intcoordinates(coords[i]), 'A' + i);
		list->next = ft_lstnew(tetris, 50);
		list = list->next;
		i++;
	}
	return (head);
}
