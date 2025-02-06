/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:11:00 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:00 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_strcmp
 * Expected files   : ft_strcmp.c
 * Allowed functions:
 * --------------------------------------------------------------------
 * 
 * Reproduce the behavior of the function strcmp (man strcmp).
 * 
 * Your function must be declared as follows:
 * 
 * int    ft_strcmp(char *s1, char *s2);
 * 
 */

/**
 * Man Page
 * 
 * STRCMP(3) (simplified)
 * 
 * NAME
 *     strcmp -- compare strings
 * SYNOPSIS
 *     #include <string.h>
 *     int strcmp(const char *s1, const char *s2);
 * DESCRIPTION
 *     The strcmp() and strncmp() functions lexicographically compare the null-
 * terminated strings s1 and s2.
 * RETURN VALUES
 *      The strcmp() and strncmp() functions return an integer greater than,
 *  equal to, or less than 0, according as the string s1 is greater than,
 *  equal to, or less than the string s2.  The comparison is done using
 *  unsigned characters, so that ‘\200’ is greater than ‘\0’.
 * 
 */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
