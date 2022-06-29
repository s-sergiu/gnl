/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:20:36 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/29 05:49:14 by ssergiu          ###   ########.fr       */
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

int	check_for_eol(char *str)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	while(str[i] != '\0')
	{
		if (str[i++] == '\n')
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		return (i);
	return (i);
}

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
		free(temp);
		temp = ft_strjoin(temp, buffer);
		if (check_for_eol(buffer))
		{
			if (check_for_eol(temp) < (int)ft_strlen(temp))
			{
				temp[check_for_eol(temp)] = '\0';
				buffer = buffer + check_for_eol(buffer);
				free(temp);
				return(temp);
			}
		}
		f = read(fd, buffer, BUFFER_SIZE + 1);
	}
	free(temp);
	return (buffer);
}

