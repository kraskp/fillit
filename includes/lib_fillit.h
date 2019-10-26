/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:18:54 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/25 19:30:18 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FILLIT_H
# define LIB_FILLIT_H

# include "../srcs/libft/includes/libft.h"
# include <fcntl.h>

//function value.. to change the spot to a correct value according to the order of blocks from a file. (1st block is 'A', second 'B'. changes have been done to the coordinates and to main. there is a new parameter in coordinates (int k) which is the index of the double array.. check main 
//while (output[i])
//coord = coordinates(output[i], i); //change i to k if it helps. 
//lets say that the first i = 0, so. if (*str == #) -> *str = 'A' + i.
//is same as 'A' + 0 = 'A'. next will be 'A' + 1 = 'B'. etc. 
//delete these comments when unnessesary. 
//idea how to make first map. since we have this coordinates which will look like in example 01020304 this max value of 4 will be our starting map. 


int		main(int argc, char **argv);
char	**input_strings(char *path, int size);
int	*ft_min(char *str);
void	value(char *str, int k);
char	*spot(char *str);
char	*coordinates(char *spot, int k);
int		block_connection(char *str);
int		block_validator(char *block);
int		check_num_blocks(int fd, char *file);

#endif
