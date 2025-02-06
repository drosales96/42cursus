/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:59:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 21:02:12 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_count_players" counts the number of player characters 
 * ('N', 'S', 'E', 'W') in a 2D map. It iterates through the map and 
 * increments a counter for each player character found.
 * 
 * @param char **map				A 2D array representing the map.
 * 
 * @return int						Returns the total number of player 
 * 									characters detected in the map.
 * 
 * The function "ft_number_players" checks if the map contains exactly one 
 * player character ('N', 'S', 'E', 'W'). It calls "ft_count_players" to 
 * count the players and logs an appropriate error message if the count is 
 * invalid.
 * 
 * @param char **map				A 2D array representing the map.
 * 
 * @return int						Returns EXIT_SUCCESS if exactly one player 
 * 									is present in the map, or EXIT_FAILURE 
 * 									otherwise.
 * 
 */

static int	ft_count_players(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == NORTH_LETTER || map[i][j] == SOUTH_LETTER || \
			map[i][j] == WEST_LETTER || map[i][j] == EAST_LETTER)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_number_players(char **map)
{
	int	index;

	index = ft_count_players(map);
	ft_players(index);
	if (index == 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
