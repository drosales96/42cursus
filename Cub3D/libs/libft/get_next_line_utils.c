/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:07:34 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/05 12:16:44 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_gnl_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_gnl_strchr(char	*str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_gnl_len(str)]);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_gnlstrjoin(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*end;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	end = (char *)malloc(sizeof(char) * (ft_gnl_len(str1) + \
	ft_gnl_len(str2) + 1));
	if (end == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		end[j++] = str1[i++];
	i = 0;
	while (str2[i])
		end[j++] = str2[i++];
	return (end[j] = '\0', free(str1), end);
}

char	*ft_alloc(int fd, char *str)
{
	char	*buff;
	ssize_t	len;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = 1;
	while (!(ft_gnl_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		str = ft_gnlstrjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_nline(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}
