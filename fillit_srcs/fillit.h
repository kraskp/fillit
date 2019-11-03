/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:01:01 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/03 16:33:31 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUFF_SIZE 8

typedef struct			s_info
{
	int					block_count;
	char				**output;
}						t_info;

typedef struct			s_etris
{
	int					*coord;
	char				value;
	struct s_etris		*next;
}						t_etris;

typedef	struct			s_map
{
	char				**mappi;
	int					maxi;
}						t_map;

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_file
{
	int					fd;
	char				*content;
	char				*content_start;
}						t_file;

void					ft_putstr(const char *s);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strnew(size_t size);
void					ft_lstaddfront(t_list **alst, t_list *new);
t_list					*ft_lstnew(void const *content, size_t content_size);
char					*ft_strchr(const char *s, int c);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strlen(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_strdel(char **as);
void					*ft_memalloc(size_t size);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
void					ft_memdel(void **ap);
void					*ft_memcpy(void *dst, const void *src, size_t n);
char					*ft_strdup(const char *s1);
void					*ft_memset(void *s, int c, size_t n);
int						get_next_line(int fd, char **line);
void					free_info(t_info *info);
void					free_mappi(char **map);
void					free_lst(t_etris *lst);
t_map					*bigger_map(t_map *map);
int						main(int argc, char **argv);
char					**input_strings(char *path, int size);
int						*ft_min(char *str);
char					*spot(char *str);
int						block_connection(char *str);
int						block_validator(char *block);
int						check_num_blocks(char *file);
char					**starting_map(int max);
int						ft_max(int blocks);
t_info					*create_info(char *file);
void					ft_exit_usage(void);
void					ft_exit_error(void);
t_etris					*create_tetris(int *arr, char c);
t_map					*create_map(t_info *info);
int						*intcoordinates(char *str);
t_etris					*create_lst(char **output);
void					fill_map(t_map *map, t_etris *t, \
						char value, int *ji);
int						solver(t_map *map, t_etris *ls);
t_map					*solve(t_etris *etris, t_map *map);
int						overlap(t_map *map, t_etris *t, int j, int i);
int						check_if_in_bounds(t_map *map, t_etris *t, \
						char axis, int z);
void					printmap(t_map *map);

#endif
