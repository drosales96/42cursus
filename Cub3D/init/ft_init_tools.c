/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:50:17 by drosales          #+#    #+#             */
/*   Updated: 2025/02/03 21:04:06 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_player_position" locates the player's initial position 
 * in the game map and sets the corresponding coordinates in the game 
 * structure.
 * It also determines the player's initial viewing angle and initializes rays 
 * for rendering.
 * 
 * @param t_cub3d *cub			Pointer to the game structure containing player
 * 								and map data.
 * @param char **map			The 2D array representing the game map.
 * 
 */

void	ft_player_position(t_cub3d *cub, char **map)
{
	int		x;
	int		y;
	char	cell;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == NORTH_LETTER || map[x][y] == SOUTH_LETTER \
				|| map[x][y] == WEST_LETTER || map[x][y] == EAST_LETTER)
			{
				cell = map[x][y];
				cub->player.x_player_pos = y + 0.5;
				cub->player.y_player_pos = x + 0.5;
				cub->player.x_map = y;
				cub->player.y_map = x;
			}
			y++;
		}
		x++;
	}
	ft_angle(cub, cell);
	ft_ray_init(cub);
}
