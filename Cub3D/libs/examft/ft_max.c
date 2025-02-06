/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:05:46 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:36:13 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_max
 * Expected files   : ft_max.c
 * Allowed functions:
 * ----------------------------------------------------------------------
 * 
 * Write the following function:
 * 
 * int		ft_max(int* tab, unsigned int len);
 * 
 * The first parameter is an array of int, the second is the number of 
 * elements in the array.
 * 
 * The function returns the largest number found in the array.
 * 
 * If the array is empty, the function returns 0.
 * 
 */

int	ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				my_max;

	i = 0;
	my_max = tab[0];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > my_max)
			my_max = tab[i];
		i++;
	}
	return (my_max);
}
