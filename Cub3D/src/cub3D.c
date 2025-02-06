/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:24:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/02 18:24:25 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "main" is the entry point for the program. It initializes 
 * the `cub3d` structure, verifies the input arguments, analyzes the map, 
 * loads textures, and starts the game loop. It also ensures proper cleanup 
 * of resources in case of errors or upon successful execution.
 * 
 * @param int argc            The number of command-line arguments passed 
 *                            to the program.
 * @param char **argv         An array of strings containing the command-line 
 *                            arguments.
 * 
 * @return int                Returns EXIT_SUCCESS (0) on successful execution 
 *                            or EXIT_FAILURE (1) if an error occurs. 
 * 
 */

int	main(int argc, char **argv)
{
	t_cub3d	cub;

	ft_print_banner();
	if (ft_control_args(argc, argv))
		return (EXIT_FAILURE);
	ft_setup(&cub);
	if (ft_analyzer(argv[1], &cub))
	{
		if (cub.map.map)
			ft_split_clear(cub.map.map);
		ft_free_textures(&cub);
		return (EXIT_FAILURE);
	}
	ft_load_textures(&cub);
	ft_game_init(&cub);
	ft_split_clear(cub.map.map);
	ft_free_textures(&cub);
	ft_erase_textures(&cub);
	return (EXIT_SUCCESS);
}
