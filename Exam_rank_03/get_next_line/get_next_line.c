#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 5000

char    *get_next_line(int fd)
{
	int     i;
	int     byte;
	char    c;
	char    *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	byte = read(fd, &c, 1);
	buffer = (char *)malloc(420000000);
	if (!buffer)
		return (NULL);
	while (byte > 0)
	{
		buffer[i] = c;
		i++;
		if (c == EOF || c == '\n')
			break ;
		byte = read(fd, &c, 1);
	}
	if (i == 0 && byte <= 0)
	{
			free (buffer);
			return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
