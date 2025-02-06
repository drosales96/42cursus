/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:12:54 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:12:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_tab_mult
 * Expected files   : ft_tab_mult.c
 * Allowed functions: write
 * ----------------------------------------------------------------
 * 
 * Write a program that displays a number's multiplication table.
 * 
 * The parameter will always be a strictly positive number that fits in an int,
 * and said number times 9 will also fit in an int.
 * 
 * If there are no parameters, the program displays \n.
 * 
 * Examples:
 * 
 * $>./ft_tab_mult 9
 * 1 x 9 = 9
 * 2 x 9 = 18
 * 3 x 9 = 27
 * 4 x 9 = 36
 * 5 x 9 = 45
 * 6 x 9 = 54
 * 7 x 9 = 63
 * 8 x 9 = 72
 * 9 x 9 = 81
 * $>./ft_tab_mult 19
 * 1 x 19 = 19
 * 2 x 19 = 38
 * 3 x 19 = 57
 * 4 x 19 = 76
 * 5 x 19 = 95
 * 6 x 19 = 114
 * 7 x 19 = 133
 * 8 x 19 = 152
 * 9 x 19 = 171
 * $>
 * $>./ft_tab_mult | cat -e
 * $
 * $> 
 * 
 */

static void	ft_putnbr(int number)
{
	char	c;

	if (number >= 10)
		ft_putnbr(number / 10);
	c = (number % 10) + 48;
	write (1, &c, 1);
}

static int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res);
}

static int	main(int argc, char *argv[])
{
	int	nbr_table;
	int	i;

	i = 1;
	nbr_table = 0;
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	nbr_table = ft_atoi(argv[1]);
	while (i < 10)
	{
		ft_putnbr(i);
		write (1, " x ", 3);
		ft_putnbr(nbr_table);
		write (1, " = ", 3);
		ft_putnbr(i * nbr_table);
		write (1, "\n", 1);
		i++;
	}
}
