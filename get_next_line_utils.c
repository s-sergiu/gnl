/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:06:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/14 16:42:24 by ssergiu          ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = -1;
	s = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (++i < (int)(ft_strlen(s1) + 1))
		s[i] = s1[i];
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2, int flag)
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
    if (flag == 1)
        free((char *)s2);
    if (flag == 2)
        free((char *)s1);
	return (str);
}

int get_newline_pos(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != 0)
        if (buffer[i++] == '\n')
            return (i);
    return (i);
}

int has_newline(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != 0)
        if (buffer[i++] == '\n')
            return (1);
    return (0);
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
        result = ft_strjoin(result, buffer, 2); //leak #2
    }
    free(buffer);
    return (result);
}
