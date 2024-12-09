/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:04:50 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 09:07:23 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_found_hex(unsigned long long nb, char c)
{
	unsigned long long	i;

	i = 0;
	if (nb >= 16)
		i += ft_found_hex(nb / 16, c);
	if (c == 'x')
		ft_found_c("0123456789abcdef"[nb % 16]);
	if (c == 'X')
		ft_found_c("0123456789ABCDEF"[nb % 16]);
	i++;
	return (i);
}
