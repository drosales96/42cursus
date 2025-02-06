/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyzer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:24:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/05 11:37:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_analyzer" analyzes the input map file, validates its 
 * extension, processes texture data, and maps the game world. It also 
 * calculates the map dimensions and handles errors gracefully.
 * 
 * @param char *argv			The file path of the map file to be analyzed.
 * @param t_cub3d *cub			A pointer to the main game structure containing 
 * 								the map and texture information.
 * 
 * @return int					Returns EXIT_SUCCESS if the file is 
 * 								successfully analyzed. Returns EXIT_FAILURE if 
 * 								any error occurs.
 * 
 * The function "ft_mapping" processes the map data from the file descriptor 
 * and assigns it to the `t_cub3d` structure. It reads the map lines, 
 * converts them into a single string, trims unwanted characters, and splits 
 * the map into the required format.
 * 
 * @param t_cub3d *cub			A pointer to the main game structure containing 
 * 								the map and texture information.
 * @param int fd				The file descriptor of the map file.
 * 
 * @return int					Returns EXIT_SUCCESS if the map is 
 * 								successfully processed. Returns EXIT_FAILURE 
 * 								if any error occurs during processing.
 * 
 */

static char	*ft_trim_str(char *s1, char *set)
{
	char	*new;

	new = ft_strtrim(s1, set);
	if (s1)
		free(s1);
	return (new);
}

int	ft_mapping(t_cub3d *cub, int fd)
{
	char	*lines;
	char	*map;

	lines = NULL;
	map = NULL;
	lines = get_next_line(fd);
	if (!lines)
		return (ft_manage_err(READ_ERR), EXIT_FAILURE);
	map = ft_matrix_to_str(lines, fd);
	if (!map)
		return (ft_manage_err(MATRIX_TO_STR_ERR), EXIT_FAILURE);
	map = ft_trim_str(map, "\n");
	if (!map)
		return (ft_manage_err(FT_STRTRIM_ERR), EXIT_FAILURE);
	if (ft_map_spliting(cub, map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_analyzer(char *argv, t_cub3d *cub)
{
	int	fd;
	int	warning;

	warning = 0;
	cub->file = argv;
	if (ft_ext_valid(cub->file) == EXIT_FAILURE)
		return (ft_manage_err(EXT_ERR), EXIT_FAILURE);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_manage_err(OPEN_ERR), EXIT_FAILURE);
	if (ft_get_textures_data(cub, &warning, &fd) || ft_mapping(cub, fd) \
	|| ft_verify_map(cub))
		warning = 1;
	close(fd);
	ft_map_dimensions(&cub->map);
	return (warning);
}
