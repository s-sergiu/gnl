/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:06:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/16 19:26:48 by ssergiu          ###   ########.fr       */
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

int check_for_eol(char *buffer)
{
    int i;
    
    i = 0;
    while(buffer[i] != '\0')
        if (buffer[i++] == '\n')
            return (i);
    return (i);
}

int check_for_nl(char *buffer)
{
    int i;
    
    i = 0;
    while(buffer[i] != '\0')
        if (buffer[i++] == '\n')
            return (1);
    return (0);
}

char    *get_one_line(int fd, char *buffer)
{   
    int     f;
    char    *temp;

    temp = ft_strjoin("", buffer);
    while (!check_for_nl(buffer))
    {
        temp = ft_strjoin(temp, buffer);
        f = read(fd, buffer, BUFFER_SIZE);
        buffer[BUFFER_SIZE] = '\0';
        buffer = buffer + buffer[check_for_eol(buffer)];
    }
    return (temp);
}
