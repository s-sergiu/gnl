/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:20:36 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/21 18:55:07 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
    char    *line;
    char    *buffer;

    buffer = NULL;
    line = NULL;
    if (check_input(fd))
        return (0);
    line = get_one_line(fd, buffer);
    return (line);
}
