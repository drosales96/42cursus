/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:06:34 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 09:07:41 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_found_u(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb > 9)
	{
		counter += ft_found_u(nb / 10);
		counter += ft_found_u(nb % 10);
	}
	else
		counter += ft_found_c(nb + '0');
	return (counter);
}
