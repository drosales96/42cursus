/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:51:21 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 09:04:21 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	counter;
	int	res;

	counter = 1;
	i = 0;
	res = 0;
	while ((str[i] == ' ') || (str[i] <= '\r' && str[i] >= '\t'))
		i++;
	if (str[i] == '-')
	{
		counter = -counter;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] == '-' || str[i] == '+')
		return (res);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * counter);
}

/*int main (void)
{	
	printf("%d", ft_atoi("+45678"));
	
	return (0);
	
}*/