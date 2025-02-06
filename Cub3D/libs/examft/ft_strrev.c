/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:12:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_strrev
 * Expected files   : ft_strrev.c
 * Allowed functions:
 * ---------------------------------------------------------------
 * 
 * Write a function that reverses (in-place) a string.
 * 
 * It must return its parameter.
 * 
 * Your function must be declared as follows:
 * 
 * char    *ft_strrev(char *str);
 * 
 */

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}
