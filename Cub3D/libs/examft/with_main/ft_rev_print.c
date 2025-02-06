/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:07:44 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:07:44 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_rev_print
 * Expected files   : ft_rev_print.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a string, and displays the string in reverse
 * followed by a newline.
 * 
 * If the number of parameters is not 1, the program displays a newline.
 * 
 * Examples:
 * 
 * $> ./ft_rev_print "zaz" | cat -e
 * zaz$
 * $> ./ft_rev_print "dub0 a POIL" | cat -e
 * LIOP a 0bud$
 * $> ./ft_rev_print | cat -e
 * $
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		while (i)
		{
			i--;
			write(1, &argv[1][i], 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}
