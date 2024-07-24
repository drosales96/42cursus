/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-16 09:36:44 by drosales          #+#    #+#             */
/*   Updated: 2024/04/16 12:49:01 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		totallen;
	size_t		i;
	size_t		j;
	char		*buffer;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	buffer = (char *)malloc(sizeof(char) * (totallen + 1));
	if (!buffer)
		return (0);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		buffer[i] = s2[j];
		j++;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
/*#include <stdio.h>

int	main()
{
	char str1[] = "HO";
	char str2[] = "LA";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
}*/
