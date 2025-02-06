/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:10:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:10:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_str_capitalizer
 * Expected files   : ft_str_capitalizer.c
 * Allowed functions: write
 * ---------------------------------------------------------------
 * 
 * Write a program that takes one or several strings and, for each argument,
 * capitalizes the first character of each word (If it's a letter, obviously),
 * puts the rest in lowercase, and displays the result on the standard output,
 * followed by a \n.
 * 
 * A "word" is defined as a part of a string delimited either by spaces/tabs, 
 * or by the start/end of the string. If a word only has one letter, it must 
 * be capitalized.
 * 
 * If there are no arguments, the progam must display \n.
 * 
 * Example:
 * 
 * $> ./ft_str_capitalizer | cat -e
 * $
 * $> ./ft_str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
 * A First Little Test$
 * $> ./ft_str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" 
 * "   But... This iS not THAT COMPLEX" 
 * "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
 * __second Test A Little Bit   Moar Complex$
 *    But... This Is Not That Complex$
 *      Okay, This Is The Last 1239809147801 But Not    The Least    T$
 * $>
 * 
 */

static void	s_capitalizer(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 97 && str[i] <= 122)
		str[i] -= 32;
	write (1, &str[i++], 1);
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		if (str[i] >= 97 && str[i] <= 122 && \
			(str[i - 1] == 32 || str[i - 1] == 9))
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
			s_capitalizer(argv[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}
