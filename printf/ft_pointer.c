/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-29 07:41:57 by drosales          #+#    #+#             */
/*   Updated: 2024-04-29 07:41:57 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(uintptr_t ptr)
{
	size_t	counter;

	counter = 0;
	counter += write (1, "0x", 2);
	counter += ft_puthex(ptr, 'x');
	return (counter);
}
