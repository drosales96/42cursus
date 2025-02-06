/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:03:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:35:34 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_is_power_of_2
 * Expected files   : ft_is_power_of_2.c
 * Allowed functions: None
 * ---------------------------------------------------------------------
 * 
 * Write a function that determines if a given number is a power of 2.
 * This function returns 1 if the given number is a power of 2, otherwise it 
 * returns 0.
 * 
 * Your function must be declared as follows:
 * 
 * int	    ft_is_power_of_2(unsigned int n);
 * 
 */

int	ft_is_power_of_2(unsigned int n)
{
	unsigned int	test;

	test = 1;
	while (test <= n)
	{
		if (test == n)
			return (1);
		test = test * 2;
	}
	return (0);
}
