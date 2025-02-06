/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:13:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:41:14 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_wdmatch
 * Expected files   : ft_wdmatch.c
 * Allowed functions: write
 * -----------------------------------------------------------
 * 
 * Write a program that takes two strings and checks whether it's possible to
 * write the first string with characters from the second string, while 
 * respecting the order in which these characters appear in the second string.
 * 
 * If it's possible, the program displays the string, followed by a \n, 
 * otherwise it simply displays a \n.
 * 
 * If the number of arguments is not 2, the program displays a \n.
 * 
 * Examples:
 * 
 * $>./ft_wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
 * faya$
 * $>./ft_wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
 * $
 * $>./ft_wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " 
 * | cat -e
 * quarante deux$
 * $>./ft_wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
 * $
 * $>./ft_wdmatch | cat -e
 * $
 *  
 */

int	main(int argc, char *argv[])
{
	int			i;
	int			len;
	const char	*s1;
	const char	*s2;

	s1 = argv[1];
	s2 = argv[2];
	i = 0;
	len = 0;
	if (argc == 3)
	{
		while (s1[len])
			len++;
		while (i < len && *s2)
		{
			if (s1[i] == *s2)
				i++;
			s2++;
		}
		if (i == len)
			write (1, s1, len);
	}
	write (1, "\n", 1);
	return (0);
}
