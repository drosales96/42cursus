/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:39:32 by drosales          #+#    #+#             */
/*   Updated: 2025/02/02 18:27:09 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_get_the_colors" extracts a pixel color from a texture 
 * at a given coordinate.
 * 
 * @param double x					The horizontal position in the texture (0-1 
 * 									range).
 * @param double size				The vertical position in the texture (0-1 
 * 									range).
 * @param mlx_texture_t *texture	Pointer to the texture containing pixel 
 * 									data.
 * 
 * @return uint32_t					Returns the extracted color in RGBA format.
 * 
 * The function "ft_rgba" converts four separate color channels (RGBA) into a 
 * single uint32_t value.
 * 
 * @param uint8_t pixel[4]			An array containing the red, green, blue, 
 *									and alpha components of a pixel.
 * 
 * @return uint32_t					Returns the combined RGBA color.
 * 
 * The function "ft_painting_col" paints a vertical column of the wall in the 
 * game's render buffer.
 * 
 * @param t_cub3d *cub				A pointer to the game structure containing 
 * 									textures.
 * @param t_ray *ray				A pointer to the ray structure with wall 
 * 									hit information.
 * @param int c						The X-coordinate of the column being 
 * 									painted.
 * 
 * The function "ft_wallsize" calculates the projected wall height on the 
 * screen.
 * It determines the smaller distance between the ray's hypotenuse distance and
 * its vertical travel distance.
 * 
 * @param t_ray *ray				A pointer to the ray structure containing 
 * 									distance data.
 * 
 * @return double					Returns the computed wall size to be used 
 * 									for rendering.
 * 
 * The function "ft_rendering" fills the background with the sky and floor 
 * colors.
 * It iterates over each pixel in the window and applies the correct color.
 * 
 * @param t_cub3d *cub				A pointer to the game structure containing
 * 									textures and rendering data.
 * 
 */

void	ft_rendering(t_cub3d *cub)
{
	int	w;
	int	h;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT)
		{
			if (h < HEIGHT / 2)
				mlx_put_pixel(cub->background, w, h++, \
				cub->textures.sky_color);
			else
				mlx_put_pixel(cub->background, w, h++, \
				cub->textures.floor_color);
		}
		w++;
	}
}

double	ft_wallsize(t_ray *ray)
{
	return (HEIGHT / ray->wall_ray_hit_dist);
}

void	ft_painting_col(t_cub3d *cub, t_ray *ray, int c)
{
	double		size;
	uint32_t	colors;
	int			i;
	int			first_pixel;
	int			pixels;

	i = 0;
	pixels = 0;
	size = ft_wallsize(ray);
	first_pixel = ((HEIGHT / 2) - (size / 2));
	if (first_pixel < 0)
	{
		pixels = -first_pixel;
		first_pixel = 0;
	}
	while (i < HEIGHT)
	{
		if (i > first_pixel && i < HEIGHT - 1)
		{
			colors = ft_walls_colors(cub, ray, \
					(i - first_pixel + pixels) / size);
			mlx_put_pixel(cub->walls, c, i, colors);
		}
		i++;
	}
}

uint32_t	ft_rgba(uint8_t pixel[4])
{
	uint32_t	p;

	p = 0;
	p |= ((uint32_t)pixel[0] << 24);
	p |= ((uint32_t)pixel[1] << 16);
	p |= ((uint32_t)pixel[2] << 8);
	p |= pixel[3];
	return (p);
}

uint32_t	ft_get_the_colors(double x, double size, mlx_texture_t *texture)
{
	uint8_t			rgba[4];
	uint32_t		indx;
	unsigned int	i;

	i = 0;
	if (!texture || !texture->pixels || x >= 1 || size >= 1)
		return (0);
	indx = ((uint32_t)(texture->height * size) * texture->width \
			+ (uint32_t)(texture->width * x)) * texture->bytes_per_pixel;
	while (i < 4)
	{
		rgba[i] = texture->pixels[indx + i];
		i++;
	}
	return (ft_rgba(rgba));
}
