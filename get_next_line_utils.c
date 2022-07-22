/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:06:23 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/22 13:04:53 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


size_t ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = -1;
	s = malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (++i < (int)(ft_strlen((char *)s1) + 1))
		s[i] = s1[i];
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = -1;
	while (++i < (int)n)
		((char *)s)[i] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	s_length;

	if (!s)
		return (NULL);
	s_length = ft_strlen((char *)s);
	if (start >= s_length)
		return (ft_calloc(1, 1));
	if (len > s_length - start)
	{
		str = (char *)malloc((s_length - start + 1) * sizeof(char));
		len = s_length - start;
	}
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (i < (int)len && s[++i] != '\0')
		str[i] = s[start + i];
	str[i] = 0;
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
		return (0);
    return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen((char *)(s1));
	s2_length = ft_strlen((char *)(s2));
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

char    *read_line(int fd)
{
    int bytes;
    char *buffer;
    char *line;
    char *temp;

    buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
    if (!buffer)
        return (0);
    bytes = read(fd, buffer, BUFFER_SIZE);
    if (bytes <= 0)
    {
        free(buffer);
        return (0);
    }
    buffer[bytes] = '\0';
    line = ft_strdup(buffer);
    while (bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes <= 0)
        {
            free(buffer);
            return (line);
        }
        buffer[bytes] = '\0';
        temp = line;
        line = ft_strjoin(line, buffer);
        free(temp);
        if (has_newline(line))
            break;
    }
    free(buffer);
    return (line);
    
    // concatenate
    // check if its newline

}

char    *get_one_line(int fd)
{
    char            *line;
    static char     *temp;
    char            *temp2;

    //read line
    line = NULL;
    if (temp == 0 || temp[0] == '\0')
        temp = read_line(fd);
    if (!temp)
        return (0);
    //transfer buffer into temp
    //move into line once it has \n
    line = ft_strdup(temp);
    if (has_newline(temp))
    {
        temp2 = line;
        line = ft_substr(line, 0, get_newline_pos(line));
        free(temp2);
        temp2 = temp;
        temp = ft_substr(temp, get_newline_pos(temp), ft_strlen(temp));;
        free(temp2);
    }

    return (line);
}

