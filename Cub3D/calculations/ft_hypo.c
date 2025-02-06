/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hipo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 18:35:30 by drosales          #+#    #+#             */
/*   Updated: 2025-01-29 18:35:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_hypo" calculates the hypotenuse distance from the player 
 * to the wall hit point based on the ray direction and collision flag.
 * It uses the Pythagorean theorem to compute the distance.
 * 
 * @param t_ray *ray      Pointer to the ray structure containing raycasting 
 *                        data such as player position, map position, and wall 
 *                        collision details.
 * 
 * @return void           Updates the "ray_hypoteneuse_dist" variable with the 
 *                        computed distance. 
 * 
 */

void	ft_hypo(t_ray *ray)
{
	if (ray->flag == 0 && ray->ray_x > 0)
		ray->ray_hypoteneuse_dist = sqrt(pow((ray->x_map - \
			ray->x_player_pos), 2) + pow((ray->wall_ray_hit_dist - \
				ray->y_player_pos), 2));
	else if (ray->flag == 0 && ray->ray_x < 0)
		ray->ray_hypoteneuse_dist = sqrt(pow(((ray->x_map + 1) - \
			ray->x_player_pos), 2) + pow((ray->wall_ray_hit_dist - \
				ray->y_player_pos), 2));
	else if (ray->flag == 1 && ray->ray_y > 0)
		ray->ray_hypoteneuse_dist = sqrt(pow((ray->wall_ray_hit_dist - \
			ray->x_player_pos), 2) + pow((ray->y_map - ray->y_player_pos), 2));
	else
		ray->ray_hypoteneuse_dist = sqrt(pow((ray->wall_ray_hit_dist - \
			ray->x_player_pos), 2) + pow(((ray->y_map + 1) - \
				ray->y_player_pos), 2));
}
