/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:15:54 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 12:01:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_spaces" checks all characters in the map to ensure 
 * they are not adjacent to forbidden spaces. It iterates through the map, 
 * validating characters like '0', 'N', 'S', 'E', and 'W'.
 * 
 * @param char **map				A 2D array representing the map.
 * 
 * @return int						Returns EXIT_SUCCESS if all spaces are 
 * 									valid, or EXIT_FAILURE if forbidden spaces 
 * 									are found.
 * 
 * The function "ft_verify_spaces_aux" checks for forbidden spaces above and 
 * below a specific map character. It ensures that no invalid spaces surround 
 * certain characters (e.g., '0', 'N', 'S', 'E', 'W').
 * 
 * @param char **map				A 2D array representing the map.
 * @param int line					The current row being checked.
 * @param int col					The current column being checked.
 * @param int output				A flag indicating if an error was found 
 * 									(1 if true).
 * 
 * @return int						Returns the updated `output` flag.
 * 
 * The function "ft_verify_spaces_aux_2" checks for forbidden spaces to the 
 * left and right of a specific map character. It ensures that no invalid 
 * spaces surround certain characters (e.g., '0', 'N', 'S', 'E', 'W').
 * 
 * @param char **map				A 2D array representing the map.
 * @param int line					The current row being checked.
 * @param int col					The current column being checked.
 * @param int output				A flag indicating if an error was found 
 * 									(1 if true).
 * 
 * @return int						Returns the updated `output` flag.
 * 
 */

static int	ft_verify_spaces_aux_2(char **map, int line, int col, int output)
{
	if (col != 0)
	{
		if (map[line][col - 1] == 32)
		{
			ft_forbidden_space(line, col - 1);
			output = 1;
		}
	}
	if ((size_t)col != ft_strlen(map[line]))
	{
		if (map[line][col + 1] == 32)
		{
			ft_forbidden_space(line, col + 1);
			output = 1;
		}
	}
	return (output);
}

static int	ft_verify_spaces_aux(char **map, int line, int col, int output)
{
	if (line != 0)
	{
		if (map[line - 1][col] == 32)
		{
			ft_forbidden_space(line - 1, col);
			output = 1;
		}
	}
	if (line != ft_count_col(map))
	{
		if (map[line + 1][col] == 32)
		{
			ft_forbidden_space(line + 1, col);
			output = 1;
		}
	}
	return (output);
}

int	ft_verify_spaces(char **map)
{
	int	x;
	int	y;
	int	output;

	x = 0;
	output = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 48 || map[x][y] == 'N' || map[x][y] == 'S' \
			|| map[x][y] == 'E' || map[x][y] == 'W')
			{
				output = ft_verify_spaces_aux(map, x, y, output);
				output = ft_verify_spaces_aux_2(map, x, y, output);
			}
			y++;
		}
		x++;
	}
	if (output == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
