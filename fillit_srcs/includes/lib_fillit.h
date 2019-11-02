/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:18:54 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/02 16:54:32 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FILLIT_H
# define LIB_FILLIT_H

# include "../../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct			s_info
{
	int					block_count;
	char				**coord;
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

int						get_next_line(int fd, char **line);
void					free_info(t_info *info);
void					free_mappi(char **map);
void					free_lst(t_etris *lst);
t_map					*bigger_map(t_map *map);
int						main(int argc, char **argv);
char					**input_strings(char *path, int size);
int						*ft_min(char *str);
char					*spot(char *str);
char					*coordinates(char *spot);
int						block_connection(char *str);
int						block_validator(char *block);
int						check_num_blocks(char *file);
char					**starting_map(int max);
int						ft_max(char **coord);
t_info					*create_info(char *file);
void					ft_exit_usage(void);
void					ft_exit_error(void);
char					**cool(int block_count, char **output);
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