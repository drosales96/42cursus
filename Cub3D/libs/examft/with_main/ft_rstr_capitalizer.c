/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstr_capitalizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:09:23 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:09:23 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_rstr_capitalizer
 * Expected files   : ft_rstr_capitalizer.c
 * Allowed functions: write
 * 
 * ---------------------------------------------------------------
 * 
 * Write a program that takes one or more strings and, for each argument, puts
 * the last character that is a letter of each word in uppercase and the rest
 * in lowercase, then displays the result followed by a \n.
 * 
 * A word is a section of string delimited by spaces/tabs or the start/end of 
 * the string. If a word has a single letter, it must be capitalized.
 * 
 * A letter is a character in the set [a-zA-Z]
 * 
 * If there are no parameters, display \n.
 * 
 * Examples:
 * 
 * $> ./ft_rstr_capitalizer | cat -e
 * $
 * $> ./ft_rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
 * A firsT littlE tesT$
 * $> ./ft_rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" 
 * "   But... This iS not THAT COMPLEX" 
 * "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
 * seconD tesT A littlE biT   moaR compleX$
 *    but... thiS iS noT thaT compleX$
 *      okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
 * $>
 * 
 */

static void	r_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		if (str[i] >= 97 && str[i] <= 122 && \
			(str[i + 1] == 32 || str[i + 1] == 9 || str[i + 1] == '\0'))
			str[i] -= 32;
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		write (1, "\n", 1);
	else
	{
		while (i < argc)
		{
			r_capitalizer(argv[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}
