/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:45:43 by drosales          #+#    #+#             */
/*   Updated: 2025/01/24 20:06:32 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_new_strjoin" concatenates two strings into a newly 
 * allocated buffer. It ensures that memory is dynamically allocated to fit 
 * both strings and frees the first string (`s1`) to prevent memory leaks.
 * 
 * @param char const *s1		The first string to be joined. It is freed 
 * 								after concatenation.
 * @param char const *s2		The second string to be joined. It remains 
 * 								unchanged.
 * 
 * @return char*				A newly allocated string containing the 
 * 								concatenation of `s1` and `s2`.
 *								Returns NULL if memory allocation fails.
 *								Returns `s2` if `s1` is NULL.
 *								Returns `s1` if `s2` is NULL.
 * 
 * 
 * 
 */

char	*ft_new_strjoin(char *s1, char *s2)
{
	size_t		totallen;
	char		*buffer;
	int			len_s1;
	int			len_s2;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	totallen = len_s1 + len_s2;
	buffer = (char *)malloc(sizeof(char) * (totallen + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, len_s1);
	ft_memcpy(buffer + len_s1, s2, len_s2);
	buffer[totallen] = '\0';
	free (s1);
	return (buffer);
}
