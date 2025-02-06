/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 18:46:16 by drosales          #+#    #+#             */
/*   Updated: 2025-01-29 18:46:16 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_vert" calculates the vertical distance the ray travels 
 * during raycasting in the game. It computes the travel distance by 
 * determining the angle difference between the player's direction and 
 * the ray's angle, then using trigonometric functions to adjust for 
 * perspective correction.
 * 
 * @param t_cub3d *cub         A pointer to the main game structure 
 *                             containing player information.
 * @param t_ray *ray           A pointer to the ray structure used in 
 *                             raycasting.
 * 
 * @return void                This function does not return a value, but 
 *                             it updates `ray->vertical_ray_travel` with 
 *                             the calculated vertical travel distance. 
 * 
 */

void	ft_vert(t_cub3d *cub, t_ray *ray)
{
	double	angle;
	double	player;

	player = cub->player.angle * (M_PI / 180);
	angle = fabs(ray->angle_ret - player);
	if (angle > M_PI)
		angle = 2 * M_PI - angle;
	ray->vertical_ray_travel = ray->ray_hypoteneuse_dist * cos(angle);
	if (ray->vertical_ray_travel < 0.0001)
		ray->vertical_ray_travel = 9999999999999.0;
}
