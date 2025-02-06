/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:04:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:35:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_itoa
 * Expected files   : ft_itoa.c
 * Allowed functions: malloc
 * ------------------------------------------------------------------
 * 
 * Write a function that takes an int and converts it to a null-terminated 
 * string.
 * The function returns the result in a char array that you must allocate.
 * 
 * Your function must be declared as follows:
 * 
 * char	*ft_itoa(int nbr); 
 * 
 */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		neg;
	char	*tmp;

	i = 0;
	neg = 0;
	tmp = (char *) malloc(12 * sizeof(char));
	if (tmp == 0 || tmp == NULL)
		return (NULL);
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	while (nbr)
	{
		tmp[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	if (neg)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}
