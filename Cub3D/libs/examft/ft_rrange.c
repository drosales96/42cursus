/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:09:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:37:18 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_rrange
 * Expected files   : ft_rrange.c
 * Allowed functions: malloc
 * -------------------------------------------------------------------
 * 
 * Write the following function:
 * 
 * int     *ft_rrange(int start, int end);
 * 
 * It must allocate (with malloc()) an array of integers, fill it with 
 * consecutive values that begin at end and end at start (Including start 
 * and end !), then return a pointer to the first value of the array.
 * 
 * Examples:
 * 
 * - With (1, 3) you will return an array containing 3, 2 and 1
 * - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
 * - With (0, 0) you will return an array containing 0.
 * - With (0, -3) you will return an array containing -3, -2, -1 and 0. * 
 * 
 */

int	*ft_rrange(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	i = 0;
	len = abs(end - start) + 1;
	range = (int *) malloc(len * sizeof(int));
	while (i < len)
	{
		if (start < end)
			range[i] = end--;
		else
			range[i] = end++;
		i++;
	}
	return (range);
}
