/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dest[len] != '\0' && len < size)
		len++;
	i = len;
	while (src[len - i] != '\0' && len + 1 < size)
	{
		dest[len] = src[len - i];
		len++;
	}
	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
