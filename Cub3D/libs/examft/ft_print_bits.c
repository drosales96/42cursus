/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:06:47 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:36:18 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_print_bits
 * Expected files   : ft_print_bits.c
 * Allowed functions: write
 * -------------------------------------------------------------
 * 
 * Write a function that takes a byte, and prints it in binary WITHOUT A 
 * NEWLINE AT THE END.
 * 
 * Your function must be declared as follows:
 * 
 * void	ft_print_bits(unsigned char octet);
 * 
 * Example, if you pass 2 to ft_print_bits, it will print "00000010"
 * 
 */

void	ft_print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + 48;
		write (1, &bit, 1);
		i--;
	}
}
