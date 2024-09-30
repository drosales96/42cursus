/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-26 06:25:15 by drosales          #+#    #+#             */
/*   Updated: 2024/05/02 08:20:03 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrf(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (ft_putstrf("(null)"));
	while (s[i])
	{
		count += ft_putcharf(s[i]);
		i++;
	}
	return (count);
}
/*#include <stdio.h>

int	main()
{
	int result;

	
	result = printf("El string es: %s", "holamundo");
	printf("\n");
	printf("resultado: %d", result);
	return (0);
}*/
