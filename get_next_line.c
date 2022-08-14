/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/14 20:23:39 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *format_stash_and_line(char **stash)
{
    char    *line;
    char    *tmp;

    tmp = *stash;
    line = ft_strjoin(*stash, "", 0); 
    line[get_newline_pos(line)] = 0;
    *stash = *stash + get_newline_pos(*stash); //leak
    *stash = ft_strdup(*stash);
    free(tmp);
    free(*stash);
    return (line);
}

char    *get_one_line(int fd)
{
    char    *result;
    char    *buffer;
    int     bytes;

    result = ft_strdup("");
    buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
    while (!has_newline(result))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == 0)
        {
            free(buffer);
            return (result);
        }
        buffer[bytes] = 0;
        result = ft_strjoin(result, buffer, 2);
    }
    free(buffer);
    return (result);
}

int check_input(int fd)
{
    if (read(fd, NULL, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    return (1);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (!check_input(fd))
        return (0);
    if (!stash)
        stash = get_one_line(fd);
    else
        stash = ft_strjoin(stash, get_one_line(fd), 1);
    if (stash[0] == 0)
    {
        free(stash);
        stash = NULL;
        return (0);
    }
    line = format_stash_and_line(&stash); // leak
    return (line);
}
