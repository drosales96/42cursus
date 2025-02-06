/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:03:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:03:13 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_fprime
 * Expected files   : ft_fprime.c
 * Allowed functions: printf, atoi
 * -------------------------------------------------------------------
 * 
 * Write a program that takes a positive int and displays its prime factors 
 * on the standard output, followed by a newline.
 * 
 * Factors must be displayed in ascending order and separated by '*', so that
 * the expression in the output gives the right result.
 * 
 * If the number of parameters is not 1, simply display a newline.
 * 
 * The input, when there is one, will be valid.
 * 
 * Examples:
 * 
 * $> ./ft_fprime 225225 | cat -e
 * 3*3*5*5*7*11*13$
 * $> ./ft_fprime 8333325 | cat -e
 * 3*3*5*5*7*11*13*37$
 * $> ./ft_fprime 9539 | cat -e
 * 9539$
 * $> ./ft_fprime 804577 | cat -e
 * 804577$
 * $> ./ft_fprime 42 | cat -e
 * 2*3*7$
 * $> ./ft_fprime 1 | cat -e
 * 1$
 * $> ./ft_fprime | cat -e
 * $
 * $> ./ft_fprime 42 21 | cat -e
 * $
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc == 2)
	{
		i = 1;
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
		while (number >= ++i)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				if (number == i)
					break ;
				printf("*");
				number /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}
