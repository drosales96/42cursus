/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-14 09:58:51 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-05-14 09:58:51 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_rline(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	str = ft_alloc(fd, str);
	if (!str)
		return (NULL);
	out = ft_nline(str);
	str = ft_rline(str);
	return (out);
}
