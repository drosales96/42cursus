/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:21:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:52:08 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
