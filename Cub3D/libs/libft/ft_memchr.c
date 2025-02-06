/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:03:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:03:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;
	char	l;

	str = (char *)s;
	l = (char)c;
	i = 0;
	while (i < n)
	{
		if (*str == l)
			return (str);
		str++;
		i++;
	}
	return (0);
}
