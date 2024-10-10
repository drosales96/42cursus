/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:10:02 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 08:46:40 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	int	ft_number_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_size(int n)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (n + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static long long	ft_convert(int n)
{
	long long	sign;

	sign = 1;
	if (n < 0)
		sign *= -n;
	else
		sign *= n;
	return (sign);
}

char	*ft_itoa(int n)
{
	int				sign;
	int				len;
	char			*buffer;
	unsigned int	nbr;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_number_len(n);
	buffer = ft_size(len);
	if (!buffer)
		return (NULL);
	*(buffer + len) = '\0';
	nbr = ft_convert(n);
	while (len--)
	{
		*(buffer + len) = '0' + nbr % 10;
		nbr /= 10;
	}
	if (sign == 1)
		*(buffer) = '-';
	return (buffer);
}
