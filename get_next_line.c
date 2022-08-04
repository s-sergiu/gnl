/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:20:36 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/04 22:11:53 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int check_input(int fd)
{
    if (read(fd, NULL, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    return (1);
}

char *get_next_line(int fd)
{
    char        *line;
    static char *stash;

    if (!check_input(fd))
        return (0);
    if (!stash)
    {
        stash = ft_strdup("");
        line = get_one_line(fd);
        format_stash_and_line(&line, &stash);
    }
    else 
    {
        line = get_one_line(fd);
        format_stash_and_line(&line, &stash);
    }
        
    return (line);
}
