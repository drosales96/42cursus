/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:32:11 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:34:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_atoi_base
 * Expected files   : ft_atoi_base.c
 * Allowed functions: None
 * ---------------------------------------------------------------
 * 
 * Write a function that converts the string argument str (base N <= 16)
 * to an integer (base 10) and returns it.
 * 
 * The characters recognized in the input are: 0123456789abcdef
 * Those are, of course, to be trimmed according to the requested base. For
 * example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
 * 
 * Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
 * 
 * Minus signs ('-') are interpreted only if they are the first character of 
 * the string.
 * 
 * Your function must be declared as follows:
 * 
 * int	ft_atoi_base(const char *str, int str_base);
 * 
 */

static int	isvalid(int chr, int baselen)
{
	char	*lcbase;
	char	*ucbase;
	int		i;

	lcbase = "0123456789abcdef";
	ucbase = "0123456789ABCDEF";
	i = 0;
	while (i < baselen)
	{
		if (chr == lcbase[i] || chr == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] && isvalid(str[i], str_base))
	{
		res *= str_base;
		if (str[i] >= 48 && str[i] <= 57)
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sign);
}
