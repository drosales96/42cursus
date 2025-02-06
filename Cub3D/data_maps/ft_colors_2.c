/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:17:28 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 20:17:56 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_control_colors" validates the format of color data (RGB) 
 * contained in a given 2D array of strings (`cell`). It ensures that:
 * - The first element is either "C" (Ceiling) or "F" (Floor).
 * - The number of commas in the data is exactly 2.
 * - The data format matches either "C/F, R,G,B" or "C/F R G B".
 * 
 * If the format is invalid, it logs an appropriate error message.
 * 
 * @param char **cell           A pointer to a 2D array of strings containing 
 *                              the color data to be validated.
 * 
 * @return int                  Returns EXIT_SUCCESS if the format is valid. 
 *                              Returns EXIT_FAILURE if the format is invalid.
 * 
 * The function "ft_comma_counter" counts the number of commas in a given 2D 
 * array of strings (`cell`). It iterates through each character in every row 
 * of the array and increments a counter for every comma encountered.
 * 
 * @param char **cell           A pointer to a 2D array of strings containing 
 *                              the data to be checked.
 * 
 * @return int                  The total number of commas found in the input.
 * 
 * The function "ft_control_colors_nbr" validates that the RGB values provided 
 * in a 2D array of strings (`cell`) are numeric and properly formatted. It 
 * checks each character to ensure it is either a digit or a comma, and logs 
 * an error message if invalid characters are found.
 * 
 * @param char **cell           A pointer to a 2D array of strings containing 
 *                              the RGB identifier and values.
 * 
 * @return int                  Returns EXIT_SUCCESS if all characters are 
 * 								valid.
 *                              Returns EXIT_FAILURE if invalid characters 
 * 								are found.
 * 
 */

int	ft_control_colors_nbr(char **cell)
{
	int	flag;
	int	row;
	int	col;

	row = 1;
	flag = 0;
	if (ft_strcmp(cell[0], FLOOR_MIN) && ft_strcmp(cell[0], CEIL_MIN))
		return (EXIT_SUCCESS);
	while (cell[row])
	{
		col = 0;
		while (cell[row][col])
		{
			if (!ft_isdigit(cell[row][col]) && (cell[row][col] != 44))
			{
				ft_manage_err_rgb(ARG_RGB_ERR, cell, row, col);
				flag = 1;
			}
			col++;
		}
		row++;
	}
	if (flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_comma_counter(char **cell)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (cell[row])
	{
		col = 0;
		while (cell[row][col])
		{
			if (cell[row][col] == 44)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

int	ft_control_colors(char **cell)
{
	if (ft_strcmp(cell[0], CEIL_MIN) && ft_strcmp(cell[0], FLOOR_MIN))
		return (EXIT_SUCCESS);
	if (ft_split_len(cell) == 2 && ft_comma_counter(cell) == 2)
		return (EXIT_SUCCESS);
	else if (ft_split_len(cell) == 4 && ft_comma_counter(cell) == 2)
		return (EXIT_SUCCESS);
	else
	{
		if (ft_comma_counter(cell) != 2)
			ft_manage_err(FORMAT_RGB_ERR);
		if (ft_split_len(cell) != 2 && ft_split_len(cell) != 4)
			ft_manage_err(FORMAT_RGB_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
