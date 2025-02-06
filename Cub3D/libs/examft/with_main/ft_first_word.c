/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 08:31:32 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 08:31:32 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Assignment name  : ft_first_word
 * Expected files   : ft_first_word.c
 * Allowed functions: write
 * ------------------------------------------------------------------------
 * 
 * Write a program that takes a string and displays its first word, followed 
 * by a newline.
 * 
 * A word is a section of string delimited by spaces/tabs or by the start/end
 * of the string.
 * 
 * If the number of parameters is not 1, or if there are no words, simply 
 * display a newline.
 * 
 * Examples:
 * 
 * $> ./ft_first_word "FOR PONY" | cat -e
 * FOR$
 * $> ./ft_first_word "this    ...   is sparta, then again, maybe   not" | cat -e
 * this$
 * 
 * $> ./ft_first_word "   " | cat -e
 * $
 * $> ./ft_first_word "a" "b" | cat -e
 * $
 * $> ./ft_first_word "  lorem,ipsum  " | cat -e
 * lorem,ipsum$
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == 9 || argv[1][i] == 32)
			i++;
		while ((argv[1][i] != 9 && argv[1][i] != 32) && argv[1][i])
		{
			write (1, &(argv[1][i]), 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
