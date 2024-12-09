/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:58:14 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 09:07:20 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_found_d(int nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483648)
	{
		counter += ft_found_c('-');
		counter += ft_found_c('2');
		counter += ft_found_d(147483648);
	}
	else if (nb < 0)
	{
		counter += ft_found_c('-');
		nb = -nb;
		counter += ft_found_d(nb);
	}
	else if (nb > 9)
	{
		counter += ft_found_d(nb / 10);
		counter += ft_found_d(nb % 10);
	}
	else
		counter += ft_found_c(nb + '0');
	return (counter);
}
