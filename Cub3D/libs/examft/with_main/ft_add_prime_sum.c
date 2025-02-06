/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prime_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 08:28:54 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 08:28:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_add_prime_sum
 * Expected files   : ft_add_prime_sum.c
 * Allowed functions: write, exit
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a positive integer as argument and displays the
 * sum of all prime numbers inferior or equal to it followed by a newline.
 * 
 * If the number of arguments is not 1, or the argument is not a positive 
 * number, just display 0 followed by a newline.
 * 
 * Yes, the examples are right.
 * 
 * Examples:
 * 
 * $>./ft_add_prime_sum 5
 * 10
 * $>./ft_add_prime_sum 7 | cat -e
 * 17$
 * $>./ft_add_prime_sum | cat -e
 * 0$
 * $>
 * 
 */

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

static int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	res *= sign;
	return (res);
}

static int	is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 2)
		return (0);
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	number;
	int	sum;

	number = 0;
	sum = 0;
	if (argc != 2 || ft_atoi(argv[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	number = ft_atoi(argv[1]);
	while (number > 1)
	{
		if (is_prime(number))
			sum += number;
		number--;
	}
	ft_putnbr(sum);
	ft_putchar('\n');
	return (0);
}
