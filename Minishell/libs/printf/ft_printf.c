/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:24:21 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 09:08:19 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_found_character(va_list *args, const char *s, int i)
{
	int	counter;

	counter = 0;
	if (s[i] == 'c')
		counter += ft_found_c(va_arg(*args, int));
	else if (s[i] == 's')
		counter = ft_found_s(va_arg(*args, char *), counter);
	else if ((s[i] == 'd') || (s[i] == 'i'))
		counter += ft_found_d(va_arg(*args, int));
	else if (s[i] == 'x' || s[i] == 'X')
		counter += ft_found_hex(va_arg(*args, unsigned int), s[i]);
	else if (s[i] == 'u')
		counter += ft_found_u(va_arg(*args, unsigned int));
	else if (s[i] == '%')
		counter += ft_found_c('%');
	else if (s[i] == 'p')
		counter += ft_found_p(va_arg(*args, uintptr_t));
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			counter += ft_found_c((char)s[i]);
		if (s[i] == '%')
		{
			i++;
			counter += ft_found_character(&args, (char *)s, i);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
