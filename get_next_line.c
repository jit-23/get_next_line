/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:17:02 by mrudloff          #+#    #+#             */
/*   Updated: 2023/06/20 12:54:46 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*ft_readed_line(char *fd_current)
{
	int		i; 
	char	*line; 

	if (fd_current[0] == 0)
		return (NULL);
	i = 0;
	while (fd_current[i] && fd_current[i] != '\n') 
		i++;
	if (fd_current[i] == '\n')
		i++;
	line = (char *)malloc((1 + i) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (fd_current[i] && fd_current[i] != '\n')
	{
		line[i] = fd_current[i];
		i++;
	}
	if (fd_current[i] == '\n') 
		line[i++] = '\n'; 
	line[i] = '\0'; 
	return (line);
}

char	*ft_move_start(char	*fd_start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (fd_start[i] && fd_start[i] != '\n') 
		i++;
	if (fd_start[i] == '\0')
	{
		free(fd_start);
		return (NULL);
	}
	if (fd_start[i] == '\n')
		i++;
	new_buff = (char *)malloc((1 + ft_strlen(fd_start) - i) * sizeof(char *));
	if (!new_buff)
		return (NULL); 
	j = 0;
	while (fd_start[i + j]) 
	{
		new_buff[j] = fd_start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(fd_start); 
	return (new_buff);
}

char	*ft_read_the_line(int fd, char *fd_str) 
{
	int n_bytes;
	char *buff;

	n_bytes = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
		//int i = 0;
	while ((ft_strchr(fd_str, '\n') == NULL)  && n_bytes != 0) 
	{
		//printf("\nfd str - %s, buff - %s  and i = %d, \n",fd_str, buff, i++);
		n_bytes = read(fd, buff, BUFFER_SIZE);
			if (n_bytes == -1)
			{
				free(buff);
				free(fd_str);
				return (NULL);
			}
		buff[n_bytes] = '\0';
		fd_str = ft_strjoin(fd_str, buff); // this is my get_next_line
	}
	free(buff);
	return (fd_str);
}

char	*get_next_line(int fd)
{                   
	static char	*fd_str;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_str = ft_read_the_line(fd, fd_str);
	if (fd_str == NULL)
		return (NULL);
	line = ft_readed_line(fd_str);
	fd_str = ft_move_start(fd_str);
	return (line);
}