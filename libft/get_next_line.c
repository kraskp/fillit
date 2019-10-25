/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:57:22 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/24 11:47:39 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*handle_file(t_list **statlist, int fd)
{
	t_list	*file;
	t_file	f;

	file = *statlist;
	while (file)
	{
		if (((t_file*)((file->content)))->fd == fd)
			return (file);
		file = file->next;
	}
	f.fd = fd;
	f.content = ft_strnew(1);
	f.content_start = f.content;
	ft_lstadd((statlist), ft_lstnew((void*)&f, sizeof(t_file)));
	return (*statlist);
}

char	*get_line(char **content)
{
	char	*line;
	size_t	len;

	if (ft_strchr(*content, '\n'))
	{
		len = ft_strchr(*content, '\n') - *content;
		line = ft_strncpy(ft_strnew(len), *content, len);
		*content += (len + 1);
	}
	else
	{
		len = ft_strlen(*content);
		line = ft_strncpy(ft_strnew(len), *content, len);
		*content += len;
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			ret;
	static t_list	*statlist;
	t_list			*file;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	file = handle_file(&statlist, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(((t_file*)((file->content)))->content =
			ft_strjoin((((t_file*)((file->content)))->content), buf)))
			return (-1);
		ft_strdel(&(((t_file*)((file->content)))->content_start));
		((t_file*)(file->content))->content_start =
			((t_file*)((file->content)))->content;
		if (ft_strchr((((t_file*)((file->content)))->content), '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(((t_file*)((file->content)))->content))
		return (0);
	if (!(*line = get_line(&((t_file*)((file->content)))->content)))
		return (-1);
	return (1);
}
