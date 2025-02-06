/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:07:09 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:36:23 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_putstr_2
 * Expected files   : ft_putstr_2.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a function that displays a string on the standard output.
 * 
 * The pointer passed to the function contains the address of the string's 
 * first character.
 * 
 * Your function must be declared as follows:
 * 
 * void	ft_putstr_2(char *str);
 * 
 */

void	ft_putstr_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
