/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:03:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:03:33 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * 
 * Assignment name  : ft_hidenp
 * Expected files   : ft_hidenp.c
 * Allowed functions: write
 * --------------------------------------------------------------
 * 
 * Write a program named hidenp that takes two strings and displays 1
 * followed by a newline if the first string is hidden in the second one,
 * otherwise displays 0 followed by a newline.
 * 
 * Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible 
 * to find each character from s1 in s2, in the same order as they appear 
 * in s1.
 * Also, the empty string is hidden in any string.
 * 1
 * If the number of parameters is not 2, the program displays a newline.
 * 
 * Examples :
 * 
 * $>./ft_hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
 * 1$
 * $>./ft_hidenp "abc" "2altrb53c.sse" | cat -e
 * 1$
 * $>./ft_hidenp "abc" "btarc" | cat -e
 * 0$
 * $>./ft_hidenp | cat -e
 * $
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (argv[1][i] == 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write (1, "\n", 1);
	return (0);
}
