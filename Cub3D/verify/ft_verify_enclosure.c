/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_enclosure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:30:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/01 14:38:55 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_closure" checks if the map is properly enclosed. 
 * It calls "ft_verify_sides" to validate the left and right boundaries of the 
 * map and logs any detected issues.
 * 
 * @param t_cub3d *details			A pointer to the main structure containing 
 * 									map details and metadata.
 * 
 * @return int						Returns EXIT_SUCCESS if the map is properly 
 * 									enclosed, or EXIT_FAILURE if any boundary 
 * 									issues are detected.
 * 
 * The function "ft_verify_sides" checks whether the left and right sides of 
 * each line in the map are valid. It iterates through the map and calls 
 * specific functions to validate the left and right sides. If an issue is 
 * detected, it logs the error and sets an output flag.
 * 
 * @param char **map				A 2D array representing the map being 
 * 									verified.
 * 
 * @return int						Returns EXIT_SUCCESS if all sides are 
 * 									valid, or EXIT_FAILURE if any issue is 
 * 									found.
 * 
 * The function "ft_verify_left_side" checks if the leftmost non-space 
 * character in a line is a valid boundary character ('1'). It skips leading 
 * spaces and verifies the boundary.
 * 
 * @param char *letter				A string representing a line in the map.
 * 
 * @return int						Returns EXIT_SUCCESS if the left boundary 
 * 									is valid, or EXIT_FAILURE if it is invalid.
 * 
 * The function "ft_verify_right_side" checks if the rightmost non-space 
 * character in a line is a valid boundary character ('1'). It skips trailing 
 * spaces and verifies the boundary.
 * 
 * @param char *letter				A string representing a line in the map.
 * 
 * @return int						Returns EXIT_SUCCESS if the right boundary 
 * 									is valid, or EXIT_FAILURE if it is invalid.
 * 
 */

static int	ft_verify_right_side(char *letter)
{
	int	index;

	index = ft_strlen(letter);
	index--;
	while (letter[index] == 32)
		index--;
	if (letter[index] != 49)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_verify_left_side(char *letter)
{
	int	index;

	index = 0;
	while (letter[index] == 32)
		index++;
	if (letter[index] != 49)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_verify_sides(char **map)
{
	int	index;
	int	output;

	index = 0;
	output = 0;
	while (map[index])
	{
		if (ft_verify_left_side(map[index]))
		{
			ft_invalid_side(index + 1, 1);
			output = 1;
		}
		if (ft_verify_right_side(map[index]))
		{
			ft_invalid_side(index + 1, 2);
			output = 1;
		}
		index++;
	}
	if (output == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_verify_closure(t_cub3d *details)
{
	int	output;

	output = 0;
	if (ft_verify_sides(details->map.map))
		output = 1;
	if (output == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
