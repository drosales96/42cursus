/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-26 06:14:31 by drosales          #+#    #+#             */
/*   Updated: 2024-04-26 06:14:31 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrf(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putcharf('-');
		count += ft_putcharf('2');
		count += ft_putnbrf(147483648);
	}
	else if (nb < 0)
	{
		count += ft_putcharf('-');
		nb = -nb;
		count += ft_putnbrf(nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbrf(nb / 10);
		count += ft_putnbrf(nb % 10);
	}
	else
	{
		count += ft_putcharf(nb + '0');
	}
	return (count);
}