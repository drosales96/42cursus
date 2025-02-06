/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:08:11 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:37:09 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/***
 *  * 
 * Assignment name  : ft_reverse_bits
 * Expected files   : ft_reverse_bits.c
 * Allowed functions:
 * -------------------------------------------------------------------
 * 
 * Write a function that takes a byte, reverses it, bit by bit (like the
 * example) and returns the result.
 * 
 * Your function must be declared as follows:
 * 
 * unsigned char	ft_reverse_bits(unsigned char octet);
 * 
 * Example:
 * 
 *   1 byte
 * _____________
 *  0010  0110
 *      ||
 *      \/
 *  0110  0100
 * 
 */

unsigned char	ft_reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 7;
	res = 0;
	while (i >= 0)
	{
		res = (res << 1 | (octet & 1));
		octet = octet >> 1;
		i--;
	}
	return (res);
}
