/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:11:19 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:10 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/***
 * 
 * Assignment name  : ft_strcpy
 * Expected files   : ft_strcpy.c
 * Allowed functions:
 * ---------------------------------------------------------------------
 * 
 * Reproduce the behavior of the function strcpy (man strcpy).
 * 
 * Your function must be declared as follows:
 * 
 * char    *ft_strcpy(char *s1, char *s2);
 * 
 */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
