/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:12 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 08:46:15 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	i;

	i = 0;
	if (!set || !s1)
		return (NULL);
	while (ft_strchr(set, *s1) && s1[i])
		s1++;
	i = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]) && i != 0)
		i--;
	return (ft_substr((char *)s1, 0, i + 1));
}

/*int	main(void)
{
	char	s1[] = "  Holaquepasa  ";
	char	set[] = " ";
	printf("%s", ft_strtrim(s1, set));

	return (0);
}*/