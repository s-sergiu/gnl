/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:20:36 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/14 18:27:15 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	char	*temp;
	int		f;

	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0 
			|| (read(fd, 0, 0) == -1))
		return (0);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	temp = ft_strjoin("", buffer);
	f = read(fd, buffer, BUFFER_SIZE + 1);
	buffer[f] = '\0';
	if (f == 0)
	{
		free(temp);
		return(NULL);
	}
	while (f != 0)
	{
	    f = read(fd, buffer, BUFFER_SIZE + 1);
	    temp = ft_strjoin("", buffer);
	}
	return (buffer);
}

