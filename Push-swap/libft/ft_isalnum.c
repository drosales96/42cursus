/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-15 12:14:54 by drosales          #+#    #+#             */
/*   Updated: 2024-04-15 12:14:54 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*#include <stdio.h>

int main()
{
    printf("%d \n", ft_isalnum('5'));
    printf("%d \n", ft_isalnum('c'));
    printf("%d \n", ft_isalnum('A'));
    printf("%d \n", ft_isalnum(' '));
    return (0);
}*/
