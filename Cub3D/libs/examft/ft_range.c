/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:07:20 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:36:39 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_range
 * Expected files   : ft_range.c
 * Allowed functions: malloc
 * ----------------------------------------------------------------
 * 
 * Write the following function:
 * 
 * int     *ft_range(int start, int end);
 * 
 * It must allocate (with malloc()) an array of integers, fill it with 
 * consecutive values that begin at start and end at end (Including start 
 * and end !), then return a pointer to the first value of the array.
 * 
 * Examples:
 * 
 * - With (1, 3) you will return an array containing 1, 2 and 3.
 * - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
 * - With (0, 0) you will return an array containing 0.
 * - With (0, -3) you will return an array containing 0, -1, -2 and -3.
 * 
 */

int	*ft_range(int start, int end)
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
			range[i] = start++;
		else
			range[i] = start--;
		i++;
	}
	return (range);
}
