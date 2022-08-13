/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/13 23:34:37 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void    format_stash_and_line(char **line, char **stash)
{
    *line = ft_strdup(*stash); //leak #1
    (*line)[get_newline_pos(*line)] = 0;
    *stash = *stash + get_newline_pos(*stash);
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
        stash = ft_strjoin(stash, get_one_line(fd)); //leak #03
    if (stash[0] == 0)
    {
        free(stash);
        stash = NULL;
        return (0);
    }
    format_stash_and_line(&line, &stash);
    return (line);
}
