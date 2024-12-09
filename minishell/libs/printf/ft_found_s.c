/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:54:36 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 09:07:32 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_found_s(char *s, int counter)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_found_s("(null)", counter));
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			counter++;
		}
	}
	return (counter);
}
