/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:49:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:20:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	first = 0;
	if (!s1 || !set)
		return (NULL);
	while (*(s1 + first) && ft_strchr(set, *(s1 + first)))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_strchr(set, *(s1 + (last - 1))))
		last--;
	return (ft_substr(s1, first, (last - first)));
}
