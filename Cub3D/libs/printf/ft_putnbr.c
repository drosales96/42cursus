/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:22:58 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:51:58 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		count += ft_putchar('0' + nb);
	}
	return (count);
}
