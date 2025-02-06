/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:06:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:27 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_pgcd
 * Expected files   : ft_pgcd.c
 * Allowed functions: printf, atoi, malloc, free
 * ---------------------------------------------------------------
 * 
 * Write a program that takes two strings representing two strictly positive
 * integers that fit in an int.
 * 
 * Display their highest common denominator followed by a newline (It's always 
 * a strictly positive integer).
 * 
 * If the number of parameters is not 2, display a newline.
 * 
 * Examples:
 * 
 * $> ./ft_pgcd 42 10 | cat -e
 * 2$
 * $> ./ft_pgcd 42 12 | cat -e
 * 6$
 * $> ./ft_pgcd 14 77 | cat -e
 * 7$
 * $> ./ft_pgcd 17 3 | cat -e
 * 1$
 * $> ./ft_pgcd | cat -e
 * $
 * 
 */

int	main(int argc, char *argv[])
{
	int	number1;
	int	number2;

	if (argc == 3)
	{
		number1 = atoi(argv[1]);
		number2 = atoi(argv[2]);
		while (number1 != number2)
		{
			if (number1 > number2)
				number1 -= number2;
			else
				number2 -= number1;
		}
		printf("%d", number1);
	}
	printf("\n");
	return (0);
}
