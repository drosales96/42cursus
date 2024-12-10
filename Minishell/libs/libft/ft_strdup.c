/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:43:01 by marigome          #+#    #+#             */
/*   Updated: 2024/12/04 20:04:56 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = (ft_strlen(s) + 1);
	ptr = (char *)malloc(i * sizeof(char));
	if (!ptr)
		return (NULL);
	else
		ft_memcpy(ptr, s, i);
	return (ptr);
}
