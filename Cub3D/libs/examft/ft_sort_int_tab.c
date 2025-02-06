/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:10:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:37:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_sort_int_tab
 * Expected files   : ft_sort_int_tab.c
 * Allowed functions:
 * -----------------------------------------------------------
 * 
 * Write the following function:
 * 
 * void ft_sort_int_tab(int *tab, unsigned int size);
 * 
 * It must sort (in-place) the 'tab' int array, that contains exactly 'size'
 * members, in ascending order.
 * 
 * Doubles must be preserved.
 * 
 * Input is always coherent. 
 * 
 */

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j += 1;
		}
		i += 1;
	}
}
