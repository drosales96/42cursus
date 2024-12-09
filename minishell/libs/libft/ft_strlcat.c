/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:18:36 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 08:46:22 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sum;

	i = 0;
	j = 0;
	sum = 0;
	while (src[sum])
		sum++;
	while (dst[j] != '\0')
		j++;
	if (dstsize <= j)
		sum += dstsize;
	else
		sum += j;
	while (src[i] && (j + 1) < dstsize)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (sum);
}
