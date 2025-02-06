/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:11:42 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:24 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_strdup
 * Expected files   : ft_strdup.c
 * Allowed functions: malloc
 * -------------------------------------------------------------------
 * 
 * Reproduce the behavior of the function strdup (man strdup).
 * 
 * Your function must be declared as follows:
 * 
 * char    *ft_strdup(char *src);
 * 
 */

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(src);
	tmp = (void *) malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
