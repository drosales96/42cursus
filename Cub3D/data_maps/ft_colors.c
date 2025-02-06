/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:08 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/05 12:47:39 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_walls_colors" determines the color of a wall pixel
 * based on the direction of the ray and the corresponding texture.
 * It selects the appropriate wall texture depending on the ray's hit direction 
 * and retrieves the color from that texture.
 * 
 * @param t_cub3d *cub      A pointer to the game structure containing 
 * 							textures.
 * @param t_ray *ray        A pointer to the ray structure that stores ray 
 *                          properties such as direction and hit distance.
 * @param double size       The size of the texture sample to fetch the color.
 * 
 * @return uint32_t         Returns the color value (RGBA format) for the 
 *                          given wall segment. If no match is found, it 
 *                          returns a default color (0x33333388).
 * 
 * The function "ft_fetch_rgb" determines the appropriate way to parse and
 * encode RGB values based on the input format. It supports two formats:
 * - Hexadecimal RGB strings ("R,G,B")
 * - Separate RGB values in multiple cells.
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB data.
 * 
 * @return unsigned int         Returns the encoded ARGB color value if valid.
 *                              Returns RGB_VALID_MAX (default value) on error.
 * 
 * The function "ft_parse_rgb_hex" parses an RGB string in "R,G,B" format and
 * encodes it into a single unsigned integer (ARGB format). It validates that
 * the input values are within the allowed range (0-255).
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB identifier and the RGB string.
 * 
 * @return unsigned int         Returns the encoded ARGB color value if valid.
 *                              Returns EXIT_FAILURE if any value is invalid.
 * 
 * The function "ft_encode_rgb" encodes RGB values into a single unsigned 
 * integer (ARGB format). It validates that the input values are within the
 * allowed range (0-255) and reports errors for invalid values.
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB identifier and values as strings.
 * 
 * @return unsigned int         Returns the encoded ARGB color value if valid.
 *                              Returns EXIT_FAILURE if any value is invalid.
 * 
 * The function "ft_handle_rgb_error" handles errors related to invalid RGB
 * color values. It prints an error message that includes the identifier and
 * the specific invalid values for red, green, or blue channels.
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB identifier and values.
 * @param int red               The red channel value.
 * @param int green             The green channel value.
 * @param int blue              The blue channel value.
 * 
 * @return void                 No return value. Logs the error message.
 * 
 */

static void	ft_handle_rgb_error(char **cell, int red, int green, int blue)
{
	ft_printf(BDRED "%s. " RESET, cell[0]);
	if (red < 0 || red > RGB_VALID_MAX)
		ft_printf(RED RR_INDICATOR RESET "%i\n", red);
	if (green < 0 || green > RGB_VALID_MAX)
		ft_printf(GREEN GR_INDICATOR RESET "%i\n", green);
	if (blue < 0 || blue > RGB_VALID_MAX)
		ft_printf(BLUE BR_INDICATOR RESET "%i\n", blue);
	ft_printf("\n");
}

static unsigned int	ft_encode_rgb(char **cell)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = 0;
	green = 0;
	blue = 0;
	if (!cell || !cell[0] || !cell[1] || !cell[2] || !cell[3])
		return (EXIT_FAILURE);
	red = ft_atoi(cell[1]);
	green = ft_atoi(cell[2]);
	blue = ft_atoi(cell[3]);
	if (red < RGB_VALID_MIN || red > RGB_VALID_MAX || green < RGB_VALID_MIN \
	|| green > RGB_VALID_MAX || blue < RGB_VALID_MIN || blue > RGB_VALID_MAX)
	{
		ft_manage_err(RGB_ERR);
		ft_handle_rgb_error(cell, red, green, blue);
		return (EXIT_FAILURE);
	}
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

static unsigned int	ft_parse_rgb_hex(char **cell)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	char			**rgb;

	red = 0;
	green = 0;
	blue = 0;
	rgb = ft_split(cell[1], ',');
	if (!rgb)
		return (ft_manage_err(SPLIT_ERR), EXIT_FAILURE);
	if (ft_split_len(rgb) != 3)
		return (ft_split_clear(rgb), EXIT_FAILURE);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	ft_split_clear(rgb);
	if (red < RGB_VALID_MIN || red > RGB_VALID_MAX || green < RGB_VALID_MIN \
	|| green > RGB_VALID_MAX || blue < RGB_VALID_MIN || blue > RGB_VALID_MAX)
	{
		ft_handle_rgb_error(cell, red, green, blue);
		return (EXIT_FAILURE);
	}
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

unsigned int	ft_fetch_rgb(char **cell)
{
	unsigned int	rgb_color;

	rgb_color = 0;
	if (ft_split_len(cell) == 2)
	{
		rgb_color = ft_parse_rgb_hex(cell);
		if (rgb_color == EXIT_FAILURE)
			return (RGB_VALID_MAX);
	}
	else if (ft_split_len(cell) == 4)
	{
		rgb_color = ft_encode_rgb(cell);
		if (rgb_color == EXIT_FAILURE)
			return (RGB_VALID_MAX);
	}
	return (rgb_color);
}

uint32_t	ft_walls_colors(t_cub3d *cub, t_ray *ray, double size)
{
	uint32_t	c;

	if (ray->flag == 0)
	{
		if (ray->ray_x > 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, cub->textures.east_text);
		if (ray->ray_x < 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, cub->textures.west_text);
		return (c);
	}
	else if (ray->flag == 1)
	{
		if (ray->ray_y > 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, \
				cub->textures.south_text);
		if (ray->ray_y < 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, \
				cub->textures.north_text);
		return (c);
	}
	return (0x33333388);
}
