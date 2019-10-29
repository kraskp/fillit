/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:18:54 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/27 18:25:57 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FILLIT_H
# define LIB_FILLIT_H

# include "../srcs/libft/includes/libft.h"
# include <fcntl.h>

typedef struct	s_info
{
	int			block_count;
	char			**coord;
	char			**output;
}				t_info;

typedef struct	s_etris
{
	int			*coord;
	char			value;
	int			x_off;
	int			y_off;
	struct	s_etris		*next;
}				t_etris;

typedef	struct	s_map
{
	char			**mappi;
	int			maxi;
}				t_map;

//void	move(t_list *lst, int y, int x);
//int				check_if_fits(t_map *map, t_etris *t, int x, int y);
t_map				*bigger_map(t_map *map);
int				main(int argc, char **argv);
char				**input_strings(char *path, int size);
int				*ft_min(char *str);
//char			*value(char **str);
char				*spot(char *str);
char				*coordinates(char *spot);
int				block_connection(char *str);
int				block_validator(char *block);
int				check_num_blocks(char *file);
char				**starting_map(int max);
int				ft_max(char **coord);
t_info				*create_info(char *file);
void				ft_exit_usage(void);
void				ft_exit_error(void);
char				**cool(int block_count, char **output);
t_etris				*create_tetris(int *arr, char c);
t_map				*create_map(t_info *info);
int				*intcoordinates(char *str);
t_etris				*create_lst(char **output);
//void			fill_map(t_map *map, t_etris *t, int x, int y);
void				fill_map(t_map *map, t_etris *t, char value);
//int			*find_empty(t_map *map);
int				solver(t_map *map, t_etris *ls);
//void	move_back_if_no_fit(t_etris  *t, int x, int y);
t_map				*solve(t_etris *etris, t_map *map);

#endif
