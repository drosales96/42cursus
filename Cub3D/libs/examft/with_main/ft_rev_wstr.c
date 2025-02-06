/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:07:56 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_rev_wstr
 * Expected files   : ft_rev_wstr.c
 * Allowed functions: write, malloc, free
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a string as a parameter, and prints its words in
 * reverse order.
 * 
 * A "word" is a part of the string bounded by spaces and/or tabs, or the
 * begin/end of the string.
 * 
 * If the number of parameters is different from 1, the program will display
 * '\n'.
 * 
 * In the parameters that are going to be tested, there won't be any 
 * "additional" spaces (meaning that there won't be additionnal spaces at the 
 * beginning or at the end of the string, and words will always be separated 
 * by exactly one space).
 * 
 * Examples:
 * 
 * $> ./ft_rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" 
 * | cat -e
 * ironic? it Isn't gatherings. love I But people! hate You$
 * $>./ft_rev_wstr "abcdefghijklm"
 * abcdefghijklm
 * $> ./ft_rev_wstr "Wingardium Leviosa" | cat -e
 * Leviosa Wingardium$
 * $> ./ft_rev_wstr | cat -e
 * $
 * $> 
 * 
 */

static int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static int	iswhitespace(char ch)
{
	if (ch == 32 || ch == 9 || ch == 10 || ch == 13)
		return (1);
	return (0);
}

static void	print_reverse(char *str)
{
	int	start_word;
	int	end_word;
	int	current_word;

	start_word = ft_strlen(str) - 1;
	while (start_word >= 0)
	{
		end_word = start_word;
		current_word = start_word;
		while (start_word >= 0 && !iswhitespace(str[start_word]))
			start_word--;
		start_word++;
		current_word = start_word;
		while (current_word <= end_word)
		{
			write (1, &str[current_word], 1);
			current_word++;
		}
		if (start_word > 0)
			write (1, " ", 1);
		start_word--;
		start_word--;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_reverse(argv[1]);
	write (1, "\n", 1);
	return (0);
}
