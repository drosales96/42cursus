/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:54:59 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 08:46:17 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen((char *)s);
	while (size > 0)
	{
		if ((char)s[size] == (char)c)
			return ((char *)&s[size]);
		size--;
	}
	if ((char)s[size] == (char)c)
		return ((char *)&s[size]);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	printf("%s", ft_strrchr("hola que taql", 'q'));
	return (0);
}*/