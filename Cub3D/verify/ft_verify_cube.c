/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:18:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/25 01:17:00 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_ids" checks for missing texture identifiers in the 
 * `t_cub3d` structure and logs errors for each missing identifier. It also 
 * adjusts the file descriptor if necessary to ensure correct file processing.
 * 
 * @param t_cub3d *cub				A pointer to the main game structure.
 * @param int *fd					A pointer to the file descriptor for the 
 * 									map file.
 * @param int i						The current line index being processed.
 * 
 * @return void						No return value. Logs errors for missing 
 * 									identifiers.
 * 
 * The function "ft_adjust_fd" repositions the file descriptor to the correct 
 * line in the file, accounting for any missing texture identifiers. This is 
 * done to ensure the program processes the correct lines in the map file.
 * 
 * @param t_cub3d *cub				A pointer to the main game structure.
 * @param int i						The current line index being processed.
 * @param int *fd					A pointer to the file descriptor to be 
 * 									adjusted.
 * 
 * @return void						No return value. Adjusts the file 
 * 									descriptor in place.
 * 
 * The function "ft_count_miss_id" counts the number of missing texture 
 * identifiers in the `t_cub3d` structure. An identifier is considered 
 * missing if its associated flag is not set to 1.
 * 
 * @param t_cub3d *cub				A pointer to the main game structure.
 * 
 * @return int						Returns the count of missing identifiers.
 * 
 */

static int	ft_count_miss_id(t_cub3d *cub)
{
	int	count;

	count = 0;
	if (cub->textures.sky_flag != 1)
		count++;
	if (cub->textures.floor_flag != 1)
		count++;
	if (cub->textures.north_flag != 1)
		count++;
	if (cub->textures.south_flag != 1)
		count++;
	if (cub->textures.east_flag != 1)
		count++;
	if (cub->textures.west_flag != 1)
		count++;
	return (count);
}

static void	ft_adjust_fd(t_cub3d *cub, int i, int *fd)
{
	int		count;
	int		k;
	char	*row;

	k = 0;
	count = ft_count_miss_id(cub);
	if (count != 0)
	{
		close(*fd);
		*fd = open(cub ->file, O_RDONLY);
		if (*fd < 0)
		{
			ft_manage_err(OPEN_MAP_ERR);
			return ;
		}
		while (k <= i - count)
		{
			row = get_next_line(*fd);
			if (row && ft_strcmp(row, "\n"))
				k++;
			free(row);
		}
	}
}

void	ft_verify_ids(t_cub3d *cub, int *fd, int i)
{
	ft_adjust_fd(cub, i, fd);
	if (cub->textures.sky_flag != 1)
		ft_manage_err_id(CEIL);
	if (cub->textures.floor_flag != 1)
		ft_manage_err_id(FLOOR);
	if (cub->textures.north_flag != 1)
		ft_manage_err_id(NORTH);
	if (cub->textures.south_flag != 1)
		ft_manage_err_id(SOUTH);
	if (cub->textures.east_flag != 1)
		ft_manage_err_id(EAST);
	if (cub->textures.west_flag != 1)
		ft_manage_err_id(WEST);
}
