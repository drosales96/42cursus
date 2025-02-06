/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:02:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 21:33:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_extremes" checks the first and last lines of the map 
 * to ensure they contain only valid boundary characters ('1' or space). It 
 * logs errors for any invalid lines and sets a failure flag.
 * 
 * @param t_cub3d *details			A structure containing map details and 
 * 									metadata.
 * @param char **map				A 2D array representing the map to verify.
 * 
 * @return int						Returns EXIT_SUCCESS if the extremes are 
 * 									valid, or EXIT_FAILURE otherwise.
 * 
 * The function "ft_verify_first_line" checks if the first line of the map 
 * contains only valid boundary characters ('1' or space). If any other 
 * character is found, it logs the error and returns EXIT_FAILURE.
 * 
 * @param char **map				A 2D array representing the map to verify.
 * 
 * @return int						Returns EXIT_SUCCESS if the first line is 
 * 									valid, or EXIT_FAILURE otherwise.
 * 
 * The function "ft_verify_last_line" checks if the last line of the map 
 * contains only valid boundary characters ('1' or space). If any other 
 * character is found, it logs the error and returns EXIT_FAILURE.
 * 
 * @param char **map				A 2D array representing the map to verify.
 * @param int end					The index of the last line of the map.
 * 
 * @return int						Returns EXIT_SUCCESS if the last line is 
 * 									valid, or EXIT_FAILURE otherwise.
 * 
 * The function "ft_verify_core" validates all characters within the map. 
 * It iterates through each row and column, calling "ft_verify_chars" to 
 * check the validity of each character. If an invalid character is found, 
 * it logs the error and sets the output flag.
 * 
 * @param char **map				A 2D array representing the map to verify.
 * 
 * @return int						Returns EXIT_SUCCESS if all characters are 
 * 									valid, or EXIT_FAILURE if any invalid 
 * 									character is found.
 * 
 * The function "ft_verify_chars" checks if a given character is valid within 
 * the context of the map. Valid characters are 'N', 'S', 'E', 'W', newline, 
 * space, and the digits '0' and '1'.
 * 
 * @param char c					The character to verify.
 * 
 * @return int						Returns EXIT_SUCCESS if the character is 
 * 									valid, or EXIT_FAILURE otherwise.
 * 
 */

static int	ft_verify_chars(char c)
{
	if (c != NORTH_LETTER && c != SOUTH_LETTER && c != EAST_LETTER && \
	c != WEST_LETTER && c != 10 && c != 32 && c != 48 && c != 49)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_verify_core(char **map)
{
	int	i;
	int	j;
	int	output;

	i = 0;
	output = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_verify_chars(map[i][j]))
			{
				ft_invalid_char(map, i, j);
				output = 1;
			}
			j++;
		}
		i++;
	}
	if (output == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_verify_last_line(char **map, int end)
{
	int	i;

	i = 0;
	while (map[end - 1][i])
	{
		if (map[end - 1][i] != 49 && map[end - 1][i] != 32)
		{
			ft_manage_err(INV_CHAR2_ERR);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_verify_first_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != 49 && map[0][i] != 32)
		{
			ft_manage_err(INV_CHAR_ERR);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_verify_extremes(t_cub3d *details, char **map)
{
	int	flag;

	flag = 0;
	if (ft_verify_first_line(map))
		flag = 1;
	if (ft_verify_last_line(map, details->map.line_map))
		flag = 1;
	if (flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
