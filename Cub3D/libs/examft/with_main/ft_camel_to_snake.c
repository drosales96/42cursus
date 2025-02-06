/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camel_to_snake.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 08:30:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 08:30:31 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_camel_to_snake
 * Expected files   : ft_camel_to_snake.c
 * Allowed functions: malloc, realloc, write
 * ---------------------------------------------------------------------
 * 
 * Write a program that takes a single string in lowerCamelCase format
 * and converts it into a string in snake_case format.
 * 
 * A lowerCamelCase string is a string where each word begins with a capital 
 * letter except for the first one.
 * 
 * A snake_case string is a string where each word is in lower case, separated 
 * by an underscore "_".
 * 
 * Examples:
 * $>./cft_amel_to_snake "hereIsACamelCaseWord"
 * here_is_a_camel_case_word
 * $>./ft_camel_to_snake "helloWorld" | cat -e
 * hello_world$
 * $>./ft_camel_to_snake | cat -e
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
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				write (1, "_", 1);
				argv[1][i] += 32;
			}
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
