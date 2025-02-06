/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:12:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:57 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_swap_bits
 * Expected files   : ft_swap_bits.c
 * Allowed functions:
 * --------------------------------------------------------------
 * 
 * Write a function that takes a byte, swaps its halves (like the example) and
 * returns the result.
 * 
 * Your function must be declared as follows:
 * 
 * unsigned char	ft_swap_bits(unsigned char octet);
 * 
 * Example:
 *   1 byte
 * _____________
 *  0100 | 0001
 *      \ /
 *      / \
 *  0001 | 0100
 * 
 */

unsigned char	ft_swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
