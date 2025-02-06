/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_mirror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 08:29:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 08:29:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/***
 * 
 * Assignment name  : ft_alpha_mirror
 * Expected files   : ft_alpha_mirror.c
 * Allowed functions: write
 * -------------------------------------------------------------------
 * 
 * Write a program called alpha_mirror that takes a string and displays this 
 * string after replacing each alphabetical character by the opposite 
 * alphabetical character, followed by a newline.
 * 
 * 'a' becomes 'z', 'Z' becomes 'A'
 * 'd' becomes 'w', 'M' becomes 'N'
 * 
 * and so on.
 * 
 * Case is not changed.
 * 
 * If the number of arguments is not 1, display only a newline.
 * 
 * Examples:
 * 
 * $>./ft_alpha_mirror "abc"
 * zyx
 * $>./ft_alpha_mirror "My horse is Amazing." | cat -e
 * Nb slihv rh Znzarmt.$
 * $>./ft_alpha_mirror | cat -e
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
			if (argv[1][i] >= 97 && argv[1][i <= 122])
				argv[1][i] = 122 - (argv[1][i] - 97);
			else if (argv[1][i] >= 65 && argv[1][i <= 90])
				argv[1][i] = 90 - (argv[1][i] - 65);
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
