/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:18:54 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 16:49:09 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FILLIT_H
# define LIB_FILLIT_H

# include "./libft/includes/libft.h"
# include <fcntl.h>

int		main(int argc, char **argv);
char	**input_strings(char *path, int size);
char	*min(char *str);
char	*spot(char *str, char *min);
char	*coordinates(char *spot);
int		block_connection(char *str);
int		block_validator(char *block);
int		check_num_blocks(int fd, char **file);

#endif
