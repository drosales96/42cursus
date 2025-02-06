/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:26:37 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:52:01 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putptr(uintptr_t	ptr)
{
	size_t	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(ptr, 'x');
	return (count);
}
