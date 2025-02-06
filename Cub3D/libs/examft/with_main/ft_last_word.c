/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:04:28 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:14 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_last_word
 * Expected files   : ft_last_word.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a string and displays its last word followed 
 * by a \n.
 * 
 * A word is a section of string delimited by spaces/tabs or by the start/end 
 * of the string.
 * 
 * If the number of parameters is not 1, or there are no words, display a 
 * newline.
 * 
 * Example:
 * 
 * $> ./ft_last_word "FOR PONY" | cat -e
 * PONY$
 * $> ./ft_last_word "this        ...       is sparta, then again, maybe    not"
 *  | cat -e
 * not$
 * $> ./ft_last_word "   " | cat -e
 * $
 * $> ./ft_last_word "a" "b" | cat -e
 * $
 * $> ./ft_last_word "  lorem,ipsum  " | cat -e
 * lorem,ipsum$
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32 && argv[1][i + 1] >= 33 && argv[1][i + 1] \
			<= 126)
				j = i + 1;
			i++;
		}
		while (argv[1][j] >= 33 && argv[1][j] <= 126)
		{
			write (1, &argv[1][j], 1);
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
