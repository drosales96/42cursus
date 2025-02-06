/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_13.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:08:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:08:55 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_rot_13
 * Expected files   : ft_rot_13.c
 * Allowed functions: write
 * --------------------------------------------------------------
 * 
 * Write a program that takes a string and displays it, replacing each of 
 * its letters by the letter 13 spaces ahead in alphabetical order.
 * 
 * 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
 * 
 * The output will be followed by a newline.
 * 
 * If the number of arguments is not 1, the program displays a newline.
 * 
 * Example:
 * 
 * $>./ft_rot_13 "abc"
 * nop
 * $>./ft_rot_13 "My horse is Amazing." | cat -e
 * Zl ubefr vf Nznmvat.$
 * $>./ft_rot_13 "AkjhZ zLKIJz , 23y " | cat -e
 * NxwuM mYXVWm , 23l $
 * $>./ft_rot_13 | cat -e
 * $
 * $>
 * $>./ft_rot_13 "" | cat -e
 * $
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 77)
				argv[1][i] += 13;
			else if (argv[1][i] >= 97 && argv[1][i] <= 109)
				argv[1][i] += 13;
			else if (argv[1][i] >= 78 && argv[1][i] <= 90)
				argv[1][i] -= 13;
			else if (argv[1][i] >= 110 && argv[1][i] <= 122)
				argv[1][i] -= 13;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
