/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/12 17:47:27 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int check_input(int fd)
{
    if (read(fd, NULL, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    return (1);
}
/*
 check if reaches end of file;
    read until it reaches eof or newline;
 step1: get one line - until it reaches newline or eof
 step2: format line and stash
 step3: return line;
*/
char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    line = NULL;
    if (!check_input(fd))
        return (0);
    if (!stash)
        stash = get_one_line(fd);
    else
        stash = ft_strjoin(stash, get_one_line(fd));
    line = format_stash_and_line(&stash);
    if (line[0] == 0)
        return (0);
    return (line);
}
