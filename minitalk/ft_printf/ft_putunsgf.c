/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsgf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-26 08:36:39 by drosales          #+#    #+#             */
/*   Updated: 2024/05/03 12:27:29 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsgf(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunsgf(n / 10);
	count += ft_putcharf(n % 10 + '0');
	return (count);
}
/*#include <stdio.h>

int main()
{
	unsigned int number = 12345;
	size_t count = 0;
	ft_putunsgf(number, &count);
	ft_putcharf('\n', &count);
	return (0);
}*/
