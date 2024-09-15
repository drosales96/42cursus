#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	byte;
	int	i = 0;
	char	*buffer;
	char	c;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(42000000);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		buffer[i] = c;
		i++;
		if (c == EOF || c == '\n')
			break ;
		byte = read(fd, &c, 1);
	}
	if (i == 0 || byte == 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
