/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-15 12:15:59 by drosales          #+#    #+#             */
/*   Updated: 2024-04-15 12:15:59 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*source;
	char	*dst;

	i = 0;
	source = (char *)src;
	dst = (char *)dest;
	if (!source && !dst)
		return (0);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
/*#include <stdio.h>

int main()
{
    char    src[] = "hola";
    char    dest[] = "buenas tardes";

    ft_memcpy(dest, src, 4);

    printf("%s", ft_memcpy(dest, dest, 4));
    return (0);
}*/
