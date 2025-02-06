/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:33:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/27 23:03:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_free_textures" frees the memory allocated for texture 
 * paths in the `t_textures` structure. It ensures that only the paths 
 * with their corresponding flags set are released.
 * 
 * @param t_cub3d *cub         A pointer to the main structure containing 
 *                             the `t_textures` data.
 * 
 * @return void                This function does not return a value. 
 *                             It modifies the `cub` structure.
 * 
 * The function "ft_erase_textures" deletes texture images from memory 
 * using the MLX library's `mlx_delete_texture` function. It ensures that 
 * all dynamically allocated textures are properly released to avoid 
 * memory leaks.
 * 
 * @param t_cub3d *cub         A pointer to the main structure containing 
 *                             the texture data.
 * 
 * @return void                This function does not return a value. 
 *                             It modifies the `cub` structure.
 * 
 * The function "ft_trim_newline" reallocates memory for a string to remove 
 * any unused space after the string's actual content, effectively trimming 
 * it to its exact length. It uses "ft_realloc" to achieve this.
 * 
 * @param char *str				A pointer to the string to be trimmed.
 * 
 * @return char*				Returns the reallocated string without extra 
 * 								memory. Returns NULL if memory allocation 
 * 								fails. 
 * 
 */

char	*ft_trim_newline(char *str)
{
	char	*trimline;

	trimline = ft_realloc(str, ft_strlen(str));
	if (!trimline)
		return (NULL);
	return (trimline);
}

void	ft_erase_textures(t_cub3d *cub)
{
	mlx_delete_texture(cub->textures.north_text);
	mlx_delete_texture(cub->textures.south_text);
	mlx_delete_texture(cub->textures.east_text);
	mlx_delete_texture(cub->textures.west_text);
}

void	ft_free_textures(t_cub3d *cub)
{
	t_textures	texture;

	texture = cub->textures;
	if (texture.north_flag)
		free(texture.north_path);
	if (texture.south_flag)
		free(texture.south_path);
	if (texture.east_flag)
		free(texture.east_path);
	if (texture.west_flag)
		free(texture.west_path);
}
