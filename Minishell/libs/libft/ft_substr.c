/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:32:29 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 08:46:09 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sbs;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sbs = (char *)malloc(sizeof(char) * (len + 1));
	if (!sbs)
		return (NULL);
	ft_strlcpy(sbs, s + start, len + 1);
	return (sbs);
}

/*#include <stdio.h>
int main(void)
{
	char    src[] = "Hola que tal";
	printf("%s", ft_substr(src, 2, 5));
	return (0);

}*/