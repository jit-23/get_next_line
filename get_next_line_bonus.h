/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:45:11 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/06/21 23:42:16 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *src);
char	*ft_read_the_line(int fd, char *fd_str);
char	*ft_strchr(char *s, int c);
char	*ft_move_start(char *start);
char	*ft_strjoin(char *start, char *buff);
char	*ft_join(char *dest, char *s1, char *s2);
#endif
