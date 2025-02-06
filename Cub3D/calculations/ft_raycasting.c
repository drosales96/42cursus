/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 17:29:28 by drosales          #+#    #+#             */
/*   Updated: 2025-01-29 17:29:28 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_raycasting" casts rays for each column of the screen 
 * to determine wall positions and render the scene accordingly.
 *
 * @param t_cub3d *cub				A pointer to the game structure.
 * @param t_player *player			A pointer to the player structure, 
 * 									containing rays.
 * 
 * The function "ft_ray_impact" initializes ray properties, calculates wall 
 * intersections, and determines the final impact point.
 *
 * @param t_cub3d *cub				A pointer to the game structure.
 * @param t_ray *ray				A pointer to the ray structure containing 
 * 									tracing data.
 * 
 * The function "ft_dist_player_to_wall" calculates the initial distances to 
 * the first grid intersection before starting DDA traversal.
 *
 * @param t_cub3d *cub				A pointer to the game structure.
 * @param t_ray *ray				A pointer to the ray structure containing 
 * 									tracing data.
 * 
 * The function "ft_wall_finder" performs a DDA (Digital Differential Analysis) 
 * algorithm to determine where the player's ray collides with a wall.
 *
 * It steps through the grid until it finds a '1' (wall).
 *
 * @param t_cub3d *cub				A pointer to the game structure.
 * @param t_ray *ray				A pointer to the ray structure containing 
 * 									tracing data.
 * 
 */

void	ft_wall_finder(t_cub3d *cub, t_ray *ray)
{
	while (cub->map.map[ray->y_map][ray->x_map] != '1')
	{
		if (ray->cell_crossing_dist_x < ray->cell_crossing_dist_y)
		{
			ray->cell_crossing_dist_x += ray->ray_dist_to_x;
			ray->x_map += ray->ray_move_x;
			ray->flag = 0;
		}
		else
		{
			ray->cell_crossing_dist_y += ray->ray_dist_to_y;
			ray->y_map += ray->ray_move_y;
			ray->flag = 1;
		}
	}
	if (ray->flag == 0)
		ray->wall_ray_hit_dist = (ray->x_map - ray->x_player_pos + \
				(1 - ray->ray_move_x) / 2) / ray->ray_x;
	else
		ray->wall_ray_hit_dist = (ray->y_map - ray->y_player_pos + \
				(1 - ray->ray_move_y) / 2) / ray->ray_y;
}

void	ft_dist_player_to_wall(t_cub3d *cub, t_ray *ray)
{
	if (ray->ray_x > 0)
		ray->cell_crossing_dist_x = (cub->player.x_map + \
			ray->ray_move_x - cub->player.x_player_pos) * ray->ray_dist_to_x;
	else
		ray->cell_crossing_dist_x = (cub->player.x_player_pos - \
			cub->player.x_map) * ray->ray_dist_to_x;
	if (ray->ray_y > 0)
		ray->cell_crossing_dist_y = (cub->player.y_map + \
			ray->ray_move_y - cub->player.y_player_pos) * ray->ray_dist_to_y;
	else
		ray->cell_crossing_dist_y = (cub->player.y_player_pos - \
			cub->player.y_map) * ray->ray_dist_to_y;
}

void	ft_ray_impact(t_cub3d *cub, t_ray *ray)
{
	ft_init_ray_values(cub, ray);
	ft_dist_player_to_wall(cub, ray);
	ft_wall_finder(cub, ray);
	if (ray->flag == 0)
		ray->ray_hit_in_map_dist = ray->y_player_pos \
				+ (ray->wall_ray_hit_dist * ray->ray_y);
	else
		ray->ray_hit_in_map_dist = ray->x_player_pos \
				+ (ray->wall_ray_hit_dist * ray->ray_x);
	if (ray->flag == 0)
		ft_vertical_impact(ray);
	else
		ft_horizontal_impact(ray);
	ft_hypo(ray);
	ft_vert(cub, ray);
}

void	ft_raycasting(t_cub3d *cub, t_player *player)
{
	int	i;

	ft_ray_init(cub);
	i = 0;
	while (i < WIDTH)
	{
		ft_ray_impact(cub, &player->ray[i]);
		ft_painting_col(cub, &player->ray[i], i);
		i++;
	}
}
