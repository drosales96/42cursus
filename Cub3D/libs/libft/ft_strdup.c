/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:17:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:17:59 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	str = (char *) malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
