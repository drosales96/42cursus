/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snake_to_camel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:09:52 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:09:52 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_snake_to_camel
 * Expected files   : ft_snake_to_camel.c
 * Allowed functions: malloc, free, realloc, write
 * ----------------------------------------------------------
 * 
 * Write a program that takes a single string in snake_case format and converts
 *  it into a string in lowerCamelCase format.
 * 
 * A snake_case string is a string where each word is in lower case, separated 
 * by an underscore "_".
 * 
 * A lowerCamelCase string is a string where each word begins with a capital 
 * letter except for the first one.
 * 
 * Examples:
 * $>./ft_camel_to_snake "here_is_a_snake_case_word"
 * hereIsASnakeCaseWord
 * $>./ft_camel_to_snake "hello_world" | cat -e
 * helloWorld$
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
			if (argv[1][i] == '_')
			{
				i++;
				argv[1][i] -= 32;
				write (1, &argv[1][i], 1);
			}
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
