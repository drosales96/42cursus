/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-15 12:16:30 by drosales          #+#    #+#             */
/*   Updated: 2024-04-15 12:16:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	void	*buffer;
	size_t	count;

	count = ft_strlen(str);
	buffer = (char *)malloc((count + 1) * sizeof(char));
	if (buffer == 0)
		return (0);
	else
	{
		ft_memcpy(buffer, str, count + 1);
	}
	return (buffer);
}
