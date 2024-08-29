/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-19 07:21:25 by drosales          #+#    #+#             */
/*   Updated: 2024/04/22 12:14:18 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennum(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

static long long	ft_signs(long long n)
{
	long long	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

static char	*memnum(size_t n)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (n + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	int				sign;
	char			*buffer;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = lennum(n);
	buffer = memnum(len);
	if (!buffer)
		return (NULL);
	*(buffer + len) = '\0';
	nbr = ft_signs(n);
	while (len--)
	{
		*(buffer + len) = 48 + nbr % 10;
		nbr /= 10;
	}
	if (sign)
		*(buffer) = 45;
	return (buffer);
}
