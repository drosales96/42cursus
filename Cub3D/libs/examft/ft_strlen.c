/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:11:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:35 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_strlen
 * Expected files   : ft_strlen.c
 * Allowed functions:
 * ---------------------------------------------------------------
 * 
 * Write a function that returns the length of a string.
 * 
 * Your function must be declared as follows:
 * 
 * int	ft_strlen(char *str);
 * 
 */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
