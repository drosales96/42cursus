/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/02 18:37:07 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_ext_valid" check the name of the map and map name 
 * extension.
 * 
 * @param char *map_name The name of map passed by argv[1].
 * 
 */

int	ft_ext_valid(char *map_name)
{
	int	size;

	size = ft_strlen(map_name);
	if (size < 4)
	{
		ft_manage_err(SHORT_NAME_ERR);
		return (EXIT_FAILURE);
	}
	if ((ft_strncmp(map_name + size - 4, ".cub", 4) != 0))
	{
		ft_manage_err(EXT_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
