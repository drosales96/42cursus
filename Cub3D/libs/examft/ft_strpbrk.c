/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:12:01 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name	: ft_strpbrk
 * Expected files	: ft_strpbrk.c
 * Allowed functions: None
 * ---------------------------------------------------------------
 * Reproduce exactly the behavior of the function strpbrk
 * (man strpbrk).
 * 
 * The function should be prototyped as follows:
 * 
 * char	*ft_strpbrk(const char *s1, const char *s2);
 * 
 */

/**
 * 
 * STRPBRK(3) (simplified)
 * 
 * NAME
 *      strpbrk –- locate multiple characters in string
 * LIBRARY
 *      Standard C Library (libc, -lc)
 * SYNOPSIS
 *      #include <string.h>
 *      char *strpbrk(const char *s, const char *charset);
 * 
 * DESCRIPTION
 *      The strpbrk() function locates in the null-terminated string s the 
 * 		first occurrence of any character in the string charset and returns 
 * 		a pointer to this character.  If no characters from charset occur 
 * 		anywhere in s strpbrk() returns NULL.
 * RETURN VALUES
 *      The strpbrk() function return a pointer to the first occurence of 
 * 		any character in the string,if no characters occur anywhere in s, 
 * 		strpbrk() returns NULL.
 * 
 */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}
