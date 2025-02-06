/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:16:06 by drosales          #+#    #+#             */
/*   Updated: 2025/02/02 18:25:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_init_walls" initializes the wall image for rendering. It 
 * creates a new image and attaches it to the game window. If any step fails, 
 * it logs an error and exits the program (current behavior needs 
 * reformulation).
 * 
 * @param t_cub3d *structure		A pointer to the main game structure.
 * @param mlx_image_t **image		A double pointer to the wall image to be 
 * 									initialized.
 * 
 * @return void
 * 
 * The function "ft_setup" initializes all game-related data in the 
 * `t_cub3d` structure, setting pointers to NULL and numeric values to 0. 
 * It ensures the game structure is in a clean state before starting.
 * 
 * @param t_cub3d *structure		A pointer to the main game structure.
 * 
 * @return int						Returns EXIT_SUCCESS on successful setup.
 * 
 * The function "ft_init_textures" initializes texture-related variables in 
 * the `t_cub3d` structure. It also calls "ft_init_coord_flags" to set texture 
 * flags to 0 and sets texture paths and colors to NULL or 0.
 * 
 * @param t_cub3d *structure		A pointer to the main game structure.
 * 
 * @return void
 * 
 * The function "ft_init_player" initializes player-related variables in the 
 * `t_cub3d` structure. This includes setting the player's map coordinates, 
 * position, and angle to default values.
 * 
 * @param t_cub3d *structure		A pointer to the main game structure.
 * 
 * @return void
 * 
 * The function "ft_init_coord_flags" initializes all texture flag values 
 * within the `t_cub3d` structure to 0. These flags are used to track if 
 * specific textures (e.g., sky, floor, walls) have been initialized.
 * 
 * @param t_cub3d *structure		A pointer to the main game structure.
 * 
 * @return void
 * 
 */

static void	ft_init_coord_flags(t_cub3d *structure)
{
	structure->textures.sky_flag = 0;
	structure->textures.floor_flag = 0;
	structure->textures.north_flag = 0;
	structure->textures.south_flag = 0;
	structure->textures.west_flag = 0;
	structure->textures.east_flag = 0;
}

static void	ft_init_player(t_cub3d *structure)
{
	structure->player.x_map = 0;
	structure->player.y_map = 0;
	structure->player.x_player_pos = 0;
	structure->player.y_player_pos = 0;
	structure->player.angle = 0;
}

static void	ft_init_textures(t_cub3d *structure)
{
	ft_init_coord_flags(structure);
	structure->textures.north_text = NULL;
	structure->textures.south_text = NULL;
	structure->textures.west_text = NULL;
	structure->textures.east_text = NULL;
	structure->textures.north_path = NULL;
	structure->textures.south_path = NULL;
	structure->textures.west_path = NULL;
	structure->textures.east_path = NULL;
	structure->textures.sky_color = 0;
	structure->textures.floor_color = 0;
}

void	ft_setup(t_cub3d *structure)
{
	ft_init_textures(structure);
	ft_init_player(structure);
	structure->mlx = NULL;
	structure->file = NULL;
	structure->map.map = NULL;
	structure->map.line_map = 0;
	structure->map.x_map = 0;
	structure->map.y_map = 0;
	structure->background = NULL;
	structure->walls = NULL;
	structure->move = 0;
	structure->ray_number = 0;
}

void	ft_init_walls(t_cub3d *structure, mlx_image_t **image)
{
	*image = mlx_new_image(structure->mlx, WIDTH, HEIGHT);
	if (!*image)
	{
		ft_manage_err(FLOOR_OR_SKY_ERR);
		exit (EXIT_FAILURE);
	}
	if (mlx_image_to_window(structure->mlx, *image, 0, 0) == -1)
	{
		ft_manage_err(IMG_TO_WINDOW_ERR);
		exit (EXIT_FAILURE);
	}
}
