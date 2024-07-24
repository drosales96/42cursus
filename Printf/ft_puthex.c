/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-26 09:38:35 by drosales          #+#    #+#             */
/*   Updated: 2024/05/02 08:19:07 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nb, char c)
{
	unsigned long long	i;

	i = 0;
	if (nb >= 16)
		i += ft_puthex(nb / 16, c);
	if (c == 'x')
		ft_putcharf("0123456789abcdef"[nb % 16]);
	if (c == 'X')
		ft_putcharf("0123456789ABCDEF"[nb % 16]);
	i++;
	return (i);
}
