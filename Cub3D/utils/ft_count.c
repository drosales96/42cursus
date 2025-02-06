/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:36:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 22:41:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_count_col" counts the number of non-null strings (rows) 
 * in a 2D array of strings. It iterates through the array until a null 
 * pointer is encountered, representing the end of the array.
 * 
 * @param char **str				A pointer to a 2D array of strings to 
 * 									count.
 * 
 * @return int						Returns the number of rows (non-null 
 * 									strings) in the 2D array. Returns 0 if the 
 * 									array is null.
 * 
 */

int	ft_count_col(char **str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}
