/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:12:28 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name	: ft_strspn
 * Expected files	: ft_strspn.c
 * Allowed functions: None
 * ---------------------------------------------------------------
 * 
 * Reproduce exactly the behavior of the strspn function 
 * (man strspn).
 * 
 * The function should be prototyped as follows:
 * 
 * size_t	ft_strspn(const char *s, const char *accept);
 * 
 */

/**
 * 
 * STRSPN(3) (simplified)
 * 
 * NAME
 *     strspn -- span a string
 * LIBRARY
 *     Standard C Library (libc, -lc)SYNOPSIS
 *     #include <string.h>
 *     size_t strspn(const char *s, const char *charset);
 * DESCRIPTION
 *     The strspn() function spans the initial part of the null-terminated * 
 * string s as long as the characters from s occur in the null-terminated 
 * string charset. In other words, it computes the string array index of the
 * first character of s which is not in charset, else the index of the first
 * null character
 * RETURN VALUES
 *     The strspn() functions return the number of characters spanned.
 * 
 */

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	size_t	check;

	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}
