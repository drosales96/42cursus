/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:10:32 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/05 11:39:22 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_get_textures_data" initializes the process of retrieving 
 * texture data from a file. It validates the file descriptor and delegates 
 * the task of processing wall texture data to "ft_get_walls_data".
 * 
 * @param t_cub3d *cub			A pointer to the main game structure containing 
 * 								texture and map information.
 * @param int *flag				A pointer to a flag that indicates whether 
 * 								an error occurred.
 * @param int *fd				A pointer to the file descriptor of the map 
 * 								file.
 * 
 * @return int					Returns EXIT_SUCCESS if all texture data is 
 * 								successfully processed. Returns EXIT_FAILURE 
 * 								if an error occurs.
 * 
 * The function "ft_get_walls_data" reads texture data for the walls of the 
 * cube (e.g., "N", "S", "E", "W") from a file. It processes a fixed number 
 * of sides (`SIDES_CUBE`), validates each texture, and adjusts the file 
 * descriptor as needed. Finally, it verifies that all required identifiers 
 * are present.
 * 
 * @param t_cub3d *cub			A pointer to the main game structure 
 * 								containing texture and map information.
 * @param int *flag				A pointer to a flag that indicates whether 
 * 								an error occurred.
 * @param int *fd				A pointer to the file descriptor of the map 
 * 								file.
 * 
 * @return int					Returns EXIT_SUCCESS if all texture data is 
 * 								successfully processed. Returns EXIT_FAILURE 
 * 								if an error occurs.
 * 
 * The function "ft_load_textures" loads texture images for the game using the
 * MLX library. It attempts to load the textures for all four cardinal 
 * directions (north, south, east, and west) from the paths specified in the 
 * `t_cub3d` structure.
 * If any texture fails to load, the function returns an error and stops 
 * further loading.
 * 
 * @param t_cub3d *cub        A pointer to the main structure containing 
 * 							  texture paths and texture objects.
 * 
 * @return int                Returns EXIT_SUCCESS if all textures are 
 * 							  successfully loaded.
 *                            Returns EXIT_FAILURE if any texture fails to
 * 							  load.
 * 
 */

int	ft_load_textures(t_cub3d *cub)
{
	cub->textures.north_text = mlx_load_png(cub->textures.north_path);
	if (!cub->textures.north_text)
		return (ft_manage_err(NORTH_ERR), EXIT_FAILURE);
	cub->textures.south_text = mlx_load_png(cub->textures.south_path);
	if (!cub->textures.south_text)
		return (ft_manage_err(SOUTH_ERR), EXIT_FAILURE);
	cub->textures.east_text = mlx_load_png(cub->textures.east_path);
	if (!cub->textures.east_text)
		return (ft_manage_err(EAST_ERR), EXIT_FAILURE);
	cub->textures.west_text = mlx_load_png(cub->textures.west_path);
	if (!cub->textures.west_text)
		return (ft_manage_err(WEST_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_get_walls_data(t_cub3d *cub, int *flag, int *fd)
{
	char	**cell;
	int		i;
	int		j;

	(void) flag;
	cell = NULL;
	i = 0;
	j = 0;
	while (i < SIDES_CUBE)
	{
		if (ft_split_line(&cell, *fd))
			return (EXIT_FAILURE);
		j++;
		if (ft_verify_texture(cub, cell, &i, j))
		{
			*fd = 1;
			return (EXIT_FAILURE);
		}
	}
	ft_verify_ids(cub, fd, i);
	return (EXIT_SUCCESS);
}

int	ft_get_textures_data(t_cub3d *cub, int *flag, int *fd)
{
	if (*fd < 0)
	{
		ft_manage_err(OPEN_MAP_ERR);
		*flag = 1;
		return (*flag);
	}
	if (ft_get_walls_data(cub, flag, fd))
	{
		*flag = 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
