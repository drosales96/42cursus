/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 08:31:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 08:31:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_epur_str
 * Expected files   : ft_epur_str.c
 * Allowed functions: write
 * --------------------------------------------------------
 * 
 * Write a program that takes a string, and displays this string with 
 * exactly one space between words, with no spaces or tabs either at the 
 * beginning or the end, followed by a \n.
 * 
 * A "word" is defined as a part of a string delimited either by spaces/tabs, 
 * or by the start/end of the string.
 * 
 * If the number of arguments is not 1, or if there are no words to display, 
 * the program displays \n.
 * 
 * Example:
 * 
 * $> ./ft_epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
 * vous voyez c'est facile d'afficher la meme chose$
 * $> ./ft_epur_str " seulement          la c'est      plus dur " | cat -e
 * seulement la c'est plus dur$
 * $> ./ft_epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" 
 * | cat -e
 * $
 * $> ./ft_epur_str "" | cat -e
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
		while ((argv[1][i] == 32 || argv[1][i] == 9) && argv[1][i])
			i++;
		while (argv[1][i])
		{
			while (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				write (1, &argv[1][i], 1);
				i++;
			}
			while (argv[1][i] == 32 && argv[1][i + 1] == 32 && argv[1][i])
				i++;
			if (argv[1][i] == '\0' || (argv[1][i] == 32 && \
				argv[1][i + 1] == '\0'))
				break ;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
