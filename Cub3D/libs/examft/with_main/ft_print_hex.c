/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:06:58 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:34 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_print_hex
 * Expected files   : ft_print_hex.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a positive (or zero) number expressed in base 10,
 * and displays it in base 16 (lowercase letters) followed by a newline.
 * 
 * If the number of parameters is not 1, the program displays a newline.
 * 
 * Examples:
 * 
 * $> ./ft_print_hex "10" | cat -e
 * a$
 * $> ./ft_print_hex "255" | cat -e
 * ff$
 * $> ./ft_print_hex "5156454" | cat -e
 * 4eae66$
 * $> ./ft_print_hex | cat -e
 * $ 
 * 
 */

static int	ft_atoi(char*str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr *= 10;
		nbr += (str[i] - 48);
		i++;
	}
	nbr *= sign;
	return (nbr);
}

static void	ft_puthex(int nbr)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16);
	nbr = "0123456789abcdef"[nbr % 16];
	write (1, &nbr, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_puthex(ft_atoi(argv[1]));
	write (1, "\n", 1);
	return (0);
}
