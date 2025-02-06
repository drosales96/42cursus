/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:16:27 by drosales          #+#    #+#             */
/*   Updated: 2025/02/02 15:07:37 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/** 
 * The function "ft_horizontal_impact" calculates the wall impact height for 
 * horizontal ray intersections.
 * It determines the visible wall height in pixels based on the distance 
 * where the ray intersects the map along the x-axis.
 * 
 * @param t_ray *ray         Pointer to the ray structure that holds ray 
 *                           intersection data.
 * 
 * @return void              Updates the `wall_ray_hit_dist` based on the 
 *                           intersection coordinates.
 * 
 * The function "ft_vertical_impact" calculates the wall impact height for 
 * vertical ray intersections.
 * It determines the visible wall height in pixels based on the distance 
 * where the ray intersects the map.
 * 
 * @param t_ray *ray         Pointer to the ray structure that holds ray 
 *                           intersection data.
 * 
 * @return void              Updates the `wall_ray_hit_dist` based on the 
 *                           intersection coordinates.
 * 
 * The function "ft_rotation" handles player rotation based on user input.
 * If the left arrow key is pressed, it rotates the player left 
 * (counterclockwise).
 * If the right arrow key is pressed, it rotates the player right (clockwise).
 * 
 * @param t_cub3d *cub       Pointer to the main game structure containing 
 *                           player data and input handling.
 * 
 * @return void              Updates the player's angle based on key input.
 * 
 * The function "ft_angles_checker" adjusts the player's angle by a given 
 * increment and ensures it stays within the range of 0 to 360 degrees.
 * 
 * @param double *angle      Pointer to the angle that needs to be adjusted.
 * @param double i           The increment (positive or negative) to apply to 
 *                           the angle.
 * 
 * @return void              The function does not return a value but updates 
 *                           the angle in place.
 * 
 */

void	ft_angles_checker(double *angle, double i)
{
	*angle += i;
	if (*angle >= 360)
		*angle -= 360;
	if (*angle < 0)
		*angle += 360;
}

void	ft_rotation(t_cub3d *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		ft_angles_checker(&cub->player.angle, -3);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		ft_angles_checker(&cub->player.angle, 3);
}

void	ft_vertical_impact(t_ray *ray)
{
	if (ray->ray_x > 0 && ray->ray_y >= 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
	else if (ray->ray_x <= 0 && ray->ray_y > 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
	else if (ray->ray_x >= 0 && ray->ray_y < 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
	else if (ray->ray_x < 0 && ray->ray_y <= 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
}

void	ft_horizontal_impact(t_ray *ray)
{
	if (ray->ray_x > 0 && ray->ray_y >= 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
	else if (ray->ray_x <= 0 && ray->ray_y > 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
	else if (ray->ray_x >= 0 && ray->ray_y < 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
	else if (ray->ray_x < 0 && ray->ray_y <= 0)
		ray->wall_visible_height = (ray->ray_hypoteneuse_dist) * \
		HEIGHT / ray->ray_hypoteneuse_dist;
}
