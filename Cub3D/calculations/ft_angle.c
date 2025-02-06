/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:09:41 by drosales          #+#    #+#             */
/*   Updated: 2025/02/03 21:03:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_angle" sets the initial player angle based on the cardinal 
 * direction they are facing.
 * 
 * @param t_cub3d *cub		Pointer to the main game structure containing 
 * 							player data.
 * @param char cardinal		Character representing the player's initial 
 * 							direction (N, S, E, W).
 * 
 * @return void				Updates the player's angle in degrees.
 * 
 */

void	ft_angle(t_cub3d *cub, char cardinal)
{
	if (cardinal == NORTH_LETTER)
		cub->player.angle = 90;
	if (cardinal == SOUTH_LETTER)
		cub->player.angle = 270;
	if (cardinal == EAST_LETTER)
		cub->player.angle = 0;
	if (cardinal == WEST_LETTER)
		cub->player.angle = 180;
}
