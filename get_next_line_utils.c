/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:06:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/20 19:07:04 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int check_input(int fd)
{
	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0
			|| (read(fd, 0, 0) == -1))
		return (0);
}

char    *get_one_line(int fd, char *buffer)
{
    return (line);
}

char    *clean_buffer(char *buffer)
{
    return (buffer);
}
