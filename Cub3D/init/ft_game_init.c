/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:58:34 by drosales          #+#    #+#             */
/*   Updated: 2025/02/05 11:35:24 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_game_init" starts the main game loop.
 * It initializes the game environment and continuously updates the game state.
 *
 * @param t_cub3d *cub			Pointer to the game structure.
 * 
 * The function "ft_playing_mode" initializes the game window and rendering.
 * It sets up the game environment, including walls, textures, and the 
 * player's initial position.
 *
 * @param t_cub3d *cub			Pointer to the game structure.
 * 
 * The function "ft_callback" handles real-time updates in the game loop.
 * It manages key inputs, updates movement and rotation, and triggers 
 * the rendering process.
 *
 * @param void *value			A pointer to the game structure (t_cub3d).
 * 
 */

static void	ft_callback(void *value)
{
	t_cub3d	*cub;

	cub = value;
	if (cub->player.ray[0].ray_dist_to_y)
		mlx_delete_image(cub->mlx, cub->walls);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	ft_moves(cub);
	ft_rotation(cub);
	ft_init_walls(cub, &cub->walls);
	ft_raycasting(cub, &cub->player);
}

void	ft_playing_mode(t_cub3d *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);
	if (!cub->mlx)
	{
		ft_manage_err(MLX_INIT_ERR);
		return ;
	}
	ft_init_walls(cub, &cub->background);
	ft_init_walls(cub, &cub->walls);
	cub->move = 4;
	ft_player_position(cub, cub->map.map);
	ft_rendering(cub);
}

void	ft_game_init(t_cub3d *cub)
{
	ft_playing_mode(cub);
	mlx_loop_hook(cub->mlx, ft_callback, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
}
