/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:30:03 by drosales          #+#    #+#             */
/*   Updated: 2024/05/29 13:52:35 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_joined(char *buffer, char *buffer2)
{
	char	*temp;

	temp = ft_strjoin(buffer, buffer2);
	free(buffer);
	return (temp);
}

static char	*reading_file(int fd, char *res)
{
	char	*buffer;
	int		to_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	to_read = 1;
	while (to_read > 0)
	{
		to_read = read(fd, buffer, BUFFER_SIZE);
		if (to_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[to_read] = 0;
		res = ft_joined(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

static char	*getdline(char *buffer)
{
	char		*making_line;
	int			i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer [i] != '\n')
		i++;
	making_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		making_line[i] = buffer [i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		making_line[i++] = '\n';
	return (making_line);
}

static char	*nextline(char *buffer)
{
	int			i;
	int			k;
	char		*making_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{	
		free (buffer);
		return (NULL);
	}
	making_line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	k = 0;
	while (buffer[i])
		making_line[k++] = buffer[i++];
	free(buffer);
	return (making_line);
}

static char	*get_next_line(int fd)
{
	char		*making_line;
	static char	*buffer[FD_SETSIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = reading_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	making_line = getdline(buffer[fd]);
	buffer[fd] = nextline(buffer[fd]);
	return (making_line);
}
