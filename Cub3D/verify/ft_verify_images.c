/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:23:43 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 20:12:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_img_data" performs a comprehensive validation of the 
 * image and color data in the configuration file. It checks for valid 
 * identifiers, paths, arguments, file existence, and RGB color formats.
 * 
 * @param char **cell           A 2D array of strings containing the image or 
 * 								color data.
 * @param int row               The row index of the current configuration 
 * 								being validated.
 * 
 * @return int                  Returns 0 if all validations pass. Returns 1 
 *                              if any validation fails.
 * 
 * The function "ft_verify_cardinals" validates the identifier in the 
 * configuration file. It checks if the identifier matches one of the expected 
 * cardinal directions ("NO", "SO", "EA", "WE") or color indicators ("C", "F").
 * 
 * @param char **cell           A 2D array of strings containing the texture 
 * 								or color identifier.
 * 
 * @return int                  Returns EXIT_SUCCESS if the identifier is 
 * 								valid.
 *                              Returns EXIT_FAILURE if the identifier is 
 * 								invalid.
 * 
 * The function "ft_verify_path" checks if the second argument in the array 
 * (the texture path) exists. If it doesn't, an error message is logged.
 * 
 * @param char **cell           A 2D array of strings containing the texture 
 * 								identifier and path.
 * @param int row               The row index of the texture in the 
 * 								configuration file, used for error reporting.
 * 
 * @return int                  Returns EXIT_SUCCESS if the path exists.
 *                              Returns EXIT_FAILURE if the path is missing.
 * 
 * The function "ft_verify_arguments" validates the structure of the input 
 * arguments. It ensures that if the identifier is not "C" or "F", the first 
 * character of the argument is not '1', which would indicate invalid input.
 * 
 * @param char **cell           A 2D array of strings containing the input 
 * 								arguments.
 * 
 * @return int                  Returns EXIT_SUCCESS if the arguments are 
 * 								valid.
 *                              Returns EXIT_FAILURE if the arguments are 
 * 								invalid.
 * 
 * The function "ft_verify_open_file" checks if the given file path is valid 
 * and can be opened. It skips validation for "C" (Ceiling) and "F" (Floor) 
 * identifiers, as they represent colors instead of files.
 * 
 * @param char *file            The identifier of the texture or color 
 * 								(e.g., "F", "C").
 * @param char *image           The file path to the texture image.
 * 
 * @return int                  Returns EXIT_SUCCESS if the file can be 
 * 								opened.
 *                              Returns EXIT_FAILURE if the file cannot 
 * 								be opened.
 * 
 */

static int	ft_verify_open_file(char *file, char *image)
{
	int	fd;

	if (!ft_strcmp(file, CEIL_MIN) || !ft_strcmp(file, FLOOR_MIN))
		return (EXIT_SUCCESS);
	fd = open(image, O_RDONLY);
	if (fd < 0)
		return (ft_manage_err(OPEN_TEXTURE_ERR), EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

static int	ft_verify_arguments(char **cell)
{
	if (cell && ft_split_len(cell) > 2 && \
	ft_strcmp(cell[0], CEIL_MIN) && \
	ft_strcmp(cell[0], FLOOR_MIN) && cell[0][0] != '1')
		return (ft_manage_err(ARG_FILE_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_verify_path(char **cell, int row)
{
	if (!cell[1])
	{
		ft_manage_err(TEXTURE_ERR);
		ft_printf(YELLOW TEXTURE_2_ERR RESET RED "%i\n", row);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_verify_cardinals(char **cell)
{
	if (ft_strcmp(cell[0], NORTH_ABBREV) && ft_strcmp(cell[0], SOUTH_ABBREV) \
	&& ft_strcmp(cell[0], EAST_ABBREV) && ft_strcmp(cell[0], WEST_ABBREV) \
	&& ft_strcmp(cell[0], CEIL_MIN) && ft_strcmp(cell[0], FLOOR_MIN))
		return (ft_manage_err(IDENT3_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_verify_img_data(char **cell, int row)
{
	int	warning;

	warning = 0;
	if (ft_verify_cardinals(cell))
		warning = 1;
	if (ft_verify_path(cell, row))
		warning = 1;
	if (ft_verify_arguments(cell))
		warning = 1;
	if (ft_verify_open_file(cell[0], cell[1]))
		warning = 1;
	if (ft_control_colors(cell))
		warning = 1;
	if (ft_control_colors_nbr(cell))
		warning = 1;
	return (warning);
}
