/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:54:44 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 08:46:30 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	char				*dst_2;
	const char			*src_2;

	dst_2 = (char *)dst;
	src_2 = (char *)src;
	i = 0;
	if (!dst_2 && !src_2)
		return (0);
	if (dst_2 > src_2)
	{
		while (len-- > 0)
			dst_2[len] = src_2[len];
	}
	else
	{
		while (i < len)
		{
			dst_2[i] = src_2[i];
			i++;
		}
	}
	return (dst);
}
