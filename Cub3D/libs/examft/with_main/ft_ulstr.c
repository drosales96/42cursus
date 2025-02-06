/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-31 09:13:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-31 09:13:06 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_ulstr
 * Expected files   : ft_ulstr.c
 * Allowed functions: write
 * ----------------------------------------------------------------
 * Write a program that takes a string and reverses the case of all its letters.
 * Other characters remain unchanged.
 * 
 * You must display the result followed by a '\n'.
 * 
 * If the number of arguments is not 1, the program displays '\n'.
 * 
 * Examples :
 * 
 * $>./ft_ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent 
 * VAnIte et auto-justification." | cat -e
 * l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT 
 * vaNiTE ET AUTO-JUSTIFICATION.$
 * $>./ft_ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  "
 *  | cat -e
 * s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
 * $>./ft_ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
 * 3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
 * $>./ft_ulstr | cat -e
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
				argv[1][i] += 32;
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
				argv[1][i] -= 32;
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
