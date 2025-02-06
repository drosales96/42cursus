/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 18:56:31 by drosales          #+#    #+#             */
/*   Updated: 2025-01-28 18:56:31 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_moves" handles player movement input.
 * It checks for key presses and moves the player accordingly.
 * 
 * @param t_cub3d *cub		Pointer to the main game structure.
 * 
 * @return void				Moves the player based on input keys.
 * 
 * The function "ft_movement" moves the player based on a given angle.
 * It calculates the displacement using trigonometric functions.
 * 
 * @param t_cub3d *cub		Pointer to the main game structure.
 * @param double angle		The movement direction in degrees.
 * 
 * @return void				Updates the player's position if movement is valid.
 * 
 * The function "ft_check_next_step" determines if the player's next step is 
 * valid and updates their position accordingly.
 * 
 * @param t_cub3d *cub		Pointer to the main game structure containing the 
 *							map and player.
 * @param double move_x		Movement displacement in the X direction.
 * @param double move_y		Movement displacement in the Y direction.
 * 
 * @return bool				Returns true (1) if the step is valid and updates 
 * 							the position.
 *							Returns false (0) if the step is blocked.
 * 
 * The function "ft_valid_movement" checks whether the player can move to a 
 * new position without colliding with walls.
 * It verifies multiple points around the player's hitbox to ensure the 
 * movement does not pass through a wall.
 * 
 * @param t_cub3d *cub		Pointer to the main game structure containing the 
 *							map and player.
 * @param double move_x		Movement displacement in the X direction.
 * @param double move_y		Movement displacement in the Y direction.
 * 
 * @return bool				Returns true (1) if movement is valid, false (0) if
 * 							a wall blocks movement.
 * 
 */

bool	ft_valid_movement(t_cub3d *cub, double move_x, double move_y)
{
	int	verify_x;
	int	verify_x2;
	int	verify_y;
	int	verify_y2;

	verify_x = (int)floor((cub->player.x_player_pos + 0.25) + (move_x / 64));
	verify_x2 = (int)floor((cub->player.x_player_pos - 0.25) + (move_x / 64));
	verify_y = (int)floor((cub->player.y_player_pos + 0.25) + (move_y / 64));
	verify_y2 = (int)floor((cub->player.y_player_pos - 0.25) + (move_y / 64));
	if (cub->map.map[verify_y][verify_x] == '1')
		return (0);
	if (cub->map.map[verify_y2][verify_x] == '1')
		return (0);
	if (cub->map.map[verify_y][verify_x2] == '1')
		return (0);
	if (cub->map.map[verify_y2][verify_x2] == '1')
		return (0);
	return (1);
}

bool	ft_check_next_step(t_cub3d *cub, double move_x, double move_y)
{
	if (!ft_valid_movement(cub, move_x, move_y))
		return (0);
	cub->player.x_map = cub->player.x_player_pos + move_x / 64;
	cub->player.y_map = cub->player.y_player_pos + move_y / 64;
	return (1);
}

void	ft_movement(t_cub3d *cub, double angle)
{
	double	move_x;
	double	move_y;

	move_x = (cos(angle * M_PI / 180) * cub->move);
	move_y = (sin(angle * M_PI / 180) * cub->move);
	if (ft_check_next_step(cub, 0, move_y))
		cub->player.y_player_pos += move_y / 64;
	if (ft_check_next_step(cub, move_x, 0))
		cub->player.x_player_pos += move_x / 64;
}

void	ft_moves(t_cub3d *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		ft_movement(cub, cub->player.angle);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		ft_movement(cub, cub->player.angle + 180);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		ft_movement(cub, cub->player.angle - 90);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		ft_movement(cub, cub->player.angle + 90);
	ft_rotation(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_E))
		cub->move = 12;
	if (!mlx_is_key_down(cub->mlx, MLX_KEY_E))
		cub->move = 8;
}
