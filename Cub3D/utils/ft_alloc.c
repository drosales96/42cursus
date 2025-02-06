/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:40:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/24 23:32:14 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_realloc" reallocates memory for a string, resizing it to 
 * a specified length. If the existing string (`hint`) is non-null, its 
 * content is preserved up to the new length; otherwise, a new string is 
 * allocated. 
 * If the allocation fails or the requested length is invalid, the old string 
 * is freed.
 * 
 * @param char *hint				A pointer to the string to be resized. Can 
 * 									be NULL to allocate a new string.
 * @param int lenght				The desired size for the new string.
 * 
 * @return char*					Returns a pointer to the newly allocated 
 * 									and resized string. Returns NULL on 
 * 									failure.
 * 
 * The function "ft_clone_and_resize" copies the content of the existing string 
 * `hint` into the newly allocated string `new_hint` up to a specified length, 
 * ensuring proper null-termination. It then frees the old string `hint` and 
 * returns the resized string.
 * 
 * @param char *new_hint			A pointer to the newly allocated memory.
 * @param char *hint				A pointer to the existing string to be 
 * 									resized.
 * @param int length				The maximum size of the new string, 
 * 									including the null-terminator.
 * 
 * @return char*					Returns the resized string (`new_hint`).
 * 
 */

static char	*ft_clone_and_resize(char *new_hint, char *hint, int lenght)
{
	int	ptr_len;

	ptr_len = ft_strlen(hint);
	if (ptr_len > lenght - 1)
		ptr_len = lenght - 1;
	ft_memcpy(new_hint, hint, ptr_len);
	new_hint[ptr_len] = '\0';
	free(hint);
	return (new_hint);
}

char	*ft_realloc(char *hint, int lenght)
{
	char	*new_hint;

	new_hint = NULL;
	if (lenght <= 0)
		return (free(hint), NULL);
	if (!hint)
	{
		new_hint = malloc(sizeof(char) * lenght);
		return (new_hint);
	}
	new_hint = malloc(sizeof(char) * (lenght + 1));
	if (!new_hint)
		return (free(hint), NULL);
	new_hint = ft_clone_and_resize(new_hint, hint, lenght);
	return (new_hint);
}
