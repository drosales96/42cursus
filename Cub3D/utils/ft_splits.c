/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:43:20 by drosales          #+#    #+#             */
/*   Updated: 2025/01/27 22:50:36 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_split_line" reads a line from a file descriptor, trims 
 * it to remove unnecessary spaces, and splits it into an array of strings 
 * based on spaces (ASCII 32). It populates the `cell` parameter with the 
 * resulting array of strings.
 * 
 * @param char ***cell				A pointer to a 2D array where the result 
 * 									of the split operation will be stored.
 * @param int fd					The file descriptor to read the line from.
 * 
 * @return int						Returns EXIT_SUCCESS on success. If an 
 * 									error occurs (e.g., read or split failure), 
 * 									it logs the error and returns EXIT_FAILURE.
 *  
 * The function "ft_split_len" calculates the number of strings in a 2D 
 * array of strings (e.g., the result of `ft_split`).
 * 
 * @param char **str				A pointer to a 2D array of strings.
 * 
 * @return int						Returns the number of strings in the array. 
 * 									Returns 0 if the input is NULL.
 * 
 * The function "ft_split_clear" frees all memory associated with a 2D array 
 * of strings (e.g., the result of `ft_split`). It iterates through each 
 * element of the array, frees it, and finally frees the array itself.
 * 
 * @param char **str				A pointer to the 2D array of strings to be 
 * 									freed.
 * 
 * @return void*					Returns NULL to indicate that the array 
 * 									has been successfully freed.
 * 
 */

void	*ft_split_clear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int	ft_split_line(char ***cell, int fd)
{
	char	*row;

	row = get_next_line(fd);
	if (!row)
	{
		ft_manage_err(READ_ERR);
		return (EXIT_FAILURE);
	}
	row = ft_trim_newline(row);
	*cell = ft_split(row, 32);
	if (!cell)
	{
		ft_manage_err(SPLIT_ERR);
		free(row);
		return (EXIT_FAILURE);
	}
	free(row);
	return (EXIT_SUCCESS);
}
