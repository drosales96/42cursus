/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:04:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:35:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_lcm
 * Expected files   : ft_lcm.c
 * Allowed functions:
 * ------------------------------------------------------------------
 * 
 * Write a function who takes two unsigned int as parameters and returns the
 * computed LCM of those parameters.
 * 
 * LCM (Lowest Common Multiple) of two non-zero integers is the smallest 
 * positive integer divisible by the both integers.
 * 
 * A LCM can be calculated in two ways:
 * 
 * - You can calculate every multiples of each integers until you have a 
 * common multiple other than 0
 * 
 * - You can use the HCF (Highest Common Factor) of these two integers 
 * and calculate as follows:
 * 
 * 	  LCM(x, y) = | x * y | / HCF(x, y)
 * 
 *   | x * y | means "Absolute value of the product of x by y"
 * 
 * If at least one integer is null, LCM is equal to 0.
 * 
 * Your function must be prototyped as follows:
 * 
 *   unsigned int    ft_lcm(unsigned int a, unsigned int b); 
 * 
*/

unsigned int	ft_lcm(unsigned int a, unsigned int b)
{
	unsigned int	g;

	if (a > b)
		g = a;
	else
		g = b;
	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if ((g % a == 0) && (g % b == 0))
			return (g);
		g++;
	}
}
