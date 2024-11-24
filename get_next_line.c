
#include "get_next_line.h"

char	*get_line(char *stash)
{
	char	*line;

	line = ft_strjoin(stash, "", 0);
	line[get_newline_pos(line)] = 0;
	return (line);
}

char	*get_rest(char *stash)
{
	char	*rest;

	rest = ft_strdup(stash + get_newline_pos(stash));
	return (rest);
}

char	*read_line(int fd)
{
	char	*result;
	char	*buffer;
	int		bytes;

	result = ft_strdup("");
	buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
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

int	check_input(int fd)
{
	if (read(fd, NULL, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*stash;
	char		*line;
	static char	*rest;

	if (!check_input(fd))
		return (0);
	if (!rest)
		stash = read_line(fd);
	else
		stash = ft_strjoin(rest, read_line(fd), 3);
	if (!stash || stash[0] == 0)
	{
		free(stash);
		stash = NULL;
		return (0);
	}
	line = get_line(stash);
	rest = get_rest(stash);
	free(stash);
	return (line);
}
