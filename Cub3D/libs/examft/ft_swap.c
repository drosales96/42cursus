/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:12:46 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:39:02 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_swap_2
 * Expected files   : ft_swap_2.c
 * Allowed functions:
 * 
 * --------------------------------------------------------------------
 * 
 * Write a function that swaps the contents of two integers the adresses 
 * of which are passed as parameters.
 * 
 * Your function must be declared as follows:
 * 
 * void	ft_swap_2(int *a, int *b);
 * 
 */

void	ft_swap_2(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
