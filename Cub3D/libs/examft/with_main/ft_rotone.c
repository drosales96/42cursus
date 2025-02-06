/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:09:04 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:55 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/***
 * 
 * Assignment name  : ft_rotone
 * Expected files   : ft_rotone.c
 * Allowed functions: write
 * ---------------------------------------------------------------
 * 
 * Write a program that takes a string and displays it, replacing each of its
 * letters by the next one in alphabetical order.
 * 
 * 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
 * 
 * The output will be followed by a \n.
 * 
 * If the number of arguments is not 1, the program displays \n.
 * 
 * Example:
 * 
 * $>./ft_rotone "abc"
 * bcd
 * $>./ft_rotone "Les stagiaires du staff ne sentent pas toujours 
 * tres bon." | cat -e
 * Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
 * $>./ft_rotone "AkjhZ zLKIJz , 23y " | cat -e
 * BlkiA aMLJKa , 23z $
 * $>./ft_rotone | cat -e
 * $
 * $>
 * $>./ft_rotone "" | cat -e
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
			if (argv[1][i] >= 65 && argv[1][i] <= 89)
				argv[1][i] += 1;
			else if (argv[1][i] == 90)
				argv[1][i] -= 25;
			else if (argv[1][i] >= 97 && argv[1][i] <= 121)
				argv[1][i] += 1;
			else if (argv[1][i] == 122)
				argv[1][i] -= 25;
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
