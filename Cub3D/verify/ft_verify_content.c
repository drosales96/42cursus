/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:55:28 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 20:13:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_texture" validates and assigns texture paths 
 * or colors based on the input data. If the data is invalid, the function 
 * logs the error. It also increments the texture count and frees memory 
 * for the processed line.
 * 
 * @param t_cub3d *cub			A pointer to the main game structure containing 
 * 								texture and color information.
 * @param char **cell			A pointer to a 2D array of strings containing 
 * 								the texture data.
 * @param int *i				A pointer to the texture count to be 
 * 								incremented.
 * @param int row				The current line being processed in the input 
 * 								file.
 * 
 * @return int					Returns EXIT_SUCCESS if the texture is valid 
 * 								and assigned. Returns EXIT_FAILURE on error.
 * 
 * The function "ft_assign_texture_path" assigns file paths for texture 
 * identifiers (e.g., "NO", "SO", "EA", "WE") in the `t_cub3d` structure. 
 * It also delegates the assignment of sky and floor colors to 
 * "ft_assign_texture_path_2".
 * 
 * @param t_cub3d *cub         A pointer to the main game structure containing 
 *                              texture and color information.
 * @param char **cell          A pointer to a 2D array of strings, where:
 *                              - cell[0] contains the identifier ("NO", "SO", 
 *                                "EA", "WE", "C", "F").
 *                              - cell[1] contains the corresponding file path 
 *                                or RGB color data.
 * 
 * @return void                No return value. Updates the `cub` structure 
 *                              in place.
 * 
 * The function "ft_assign_texture_path_primary" assigns file paths 
 * for the NORTH ("NO") and SOUTH ("SO") texture identifiers in the `t_cub3d` 
 * structure. It ensures that each identifier is assigned only once, 
 * logging an error if a duplicate is found.
 * 
 * @param t_cub3d *cub         A pointer to the main game structure containing 
 *                              texture and color information.
 * @param char **cell          A pointer to a 2D array of strings, where:
 *                              - cell[0] contains the identifier ("NO", "SO").
 *                              - cell[1] contains the corresponding file path.
 * 
 * @return void                No return value. Updates the `cub` structure 
 *                              in place.
 * 
 * The function "ft_assign_texture_path_secondary" assigns file paths 
 * for the EAST ("EA") and WEST ("WE") texture identifiers in the `t_cub3d` 
 * structure. It ensures that each identifier is assigned only once, 
 * logging an error if a duplicate is found.
 * 
 * @param t_cub3d *cub         A pointer to the main game structure containing 
 *                              texture and color information.
 * @param char **cell          A pointer to a 2D array of strings, where:
 *                              - cell[0] contains the identifier ("EA", "WE").
 *                              - cell[1] contains the corresponding file path.
 * 
 * @return void                No return value. Updates the `cub` structure 
 *                              in place.
 * 
 * The function "ft_assign_texture_path_2" assigns the RGB colors for the 
 * sky ("C") and floor ("F") identifiers in the `t_cub3d` structure. It 
 * also sets flags to indicate that these textures have been assigned.
 * 
 * @param t_cub3d *cub			A pointer to the main game structure 
 * 								containing texture and color information.
 * @param char **cell			A pointer to a 2D array of strings, where:
 * 								- cell[0] contains the identifier ("C", "F").
 * 								- cell[1] contains the corresponding RGB color
 * 								  data.
 * 
 * @return void					No return value. Updates the `cub` structure 
 * 								in place.
 * 
 */

static void	ft_assign_texture_path_2(t_cub3d *cub, char **cell)
{
	if (cell[0] && cell[1] && !ft_strcmp(cell[0], CEIL_MIN))
	{
		cub->textures.sky_color = ft_fetch_rgb(cell);
		cub->textures.sky_flag = 1;
	}
	else if (cell[0] && cell[1] && !ft_strcmp(cell[0], FLOOR_MIN))
	{
		cub->textures.floor_color = ft_fetch_rgb(cell);
		cub->textures.floor_flag = 1;
	}
}

static void	ft_assign_texture_path_secondary(t_cub3d *cub, char **cell)
{
	if (!ft_strcmp(cell[0], EAST_ABBREV))
	{
		if (cub->textures.east_path != NULL)
		{
			ft_manage_err(DUP_EA_ERR);
			return ;
		}
		cub->textures.east_path = ft_strdup(cell[1]);
		cub->textures.east_flag = 1;
	}
	else if (!ft_strcmp(cell[0], WEST_ABBREV))
	{
		if (cub->textures.west_path != NULL)
		{
			ft_manage_err(DUP_WE_ERR);
			return ;
		}
		cub->textures.west_path = ft_strdup(cell[1]);
		cub->textures.west_flag = 1;
	}
}

static void	ft_assign_texture_path_primary(t_cub3d *cub, char **cell)
{
	if (!ft_strcmp(cell[0], NORTH_ABBREV))
	{
		if (cub->textures.north_path != NULL)
		{
			ft_manage_err(DUP_NO_ERR);
			return ;
		}
		cub->textures.north_path = ft_strdup(cell[1]);
		cub->textures.north_flag = 1;
	}
	else if (!ft_strcmp(cell[0], SOUTH_ABBREV))
	{
		if (cub->textures.south_path != NULL)
		{
			ft_manage_err(DUP_SO_ERR);
			return ;
		}
		cub->textures.south_path = ft_strdup(cell[1]);
		cub->textures.south_flag = 1;
	}
}

static void	ft_assign_texture_path(t_cub3d *cub, char **cell)
{
	if (cell[0] && cell[1])
	{
		ft_assign_texture_path_primary(cub, cell);
		ft_assign_texture_path_secondary(cub, cell);
		ft_assign_texture_path_2(cub, cell);
	}
}

int	ft_verify_texture(t_cub3d *cub, char **cell, int *i, int row)
{
	if (!cell[0])
		return (ft_split_clear(cell), EXIT_SUCCESS);
	if (ft_verify_img_data(cell, row))
	{
		ft_assign_texture_path(cub, cell);
		ft_split_clear(cell);
		*i += 1;
		return (EXIT_FAILURE);
	}
	ft_assign_texture_path(cub, cell);
	ft_split_clear(cell);
	*i += 1;
	return (EXIT_SUCCESS);
}
