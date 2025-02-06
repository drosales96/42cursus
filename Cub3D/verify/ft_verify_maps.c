/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:12:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/01 14:39:47 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_map" performs a comprehensive validation of the 
 * map structure within the `t_cub3d` input. It checks for proper closure, 
 * valid boundaries, valid spaces, and the correct number of players in the 
 * map.
 * 
 * @param t_cub3d *input			A pointer to the main structure containing 
 * 									map details and metadata.
 * 
 * @return int						Returns EXIT_SUCCESS if the map passes all 
 * 									validations, or EXIT_FAILURE if any 
 * 									validation fails.
 * 
 */

int	ft_verify_map(t_cub3d *input)
{
	int	warning;

	warning = 0;
	if (!input || !input->map.map)
		return (EXIT_FAILURE);
	if (ft_verify_extremes(input, input->map.map) || \
	ft_verify_core(input->map.map) || ft_verify_closure(input) || \
	ft_verify_spaces(input->map.map) || ft_number_players(input->map.map))
		warning = 1;
	if (warning == 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
