/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:06:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/21 19:14:52 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	i = -1;
	str = malloc(s1_length + s2_length + 1);
	if (!str)
		return (NULL);
	while (++i < (int)s1_length)
		str[i] = s1[i];
	i = -1;
	while (++i < (int)s2_length)
		str[i + s1_length] = s2[i];
	str[i + s1_length] = 0;
	return (str);
}

int get_newline_pos(char *string)
{
    int i;

    i = 0;
    while (string[i] != '\0')
        if (string[i++] == '\n')
            return (i);
    return (0);
}

int has_newline(char *string)
{
    int i;

    i = 0;
    while (string[i] != '\0')
        if (string[i++] == '\n')
            return (1);
    return (0);
}

int check_input(int fd)
{
	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0
			|| (read(fd, 0, 0) == -1))
		return (1);
    return (0);
}

char    *get_one_line(int fd, char *buffer)
{
    char        *line;
    int         bytes;
    static char *temp;

    buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
    bytes = read(fd, buffer, BUFFER_SIZE);
    if (!bytes)
    {
        free(buffer);
        return (0);
    }
    buffer[BUFFER_SIZE] = '\0';
    line = ft_strjoin("", buffer);

    while (!has_newline(buffer))
    {
        bytes = read(fd, buffer, BUFFER_SIZE + 1);
        buffer[BUFFER_SIZE] = '\0';
        line = ft_strjoin(line, buffer);
    }
    line[get_newline_pos(line)] = '\0';
    temp = clean_buffer(buffer);
    free(buffer);
    return (line);
}

char    *clean_buffer(char *buffer)
{
    buffer = buffer + get_newline_pos(buffer);
    return (buffer);
}
