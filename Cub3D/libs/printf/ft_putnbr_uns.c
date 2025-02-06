/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:25:41 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:51:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr_uns(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr_uns(nb / 10);
	count += ft_putchar('0' + nb % 10);
	return (count);
}
