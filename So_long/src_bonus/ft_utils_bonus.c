/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:48:54 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 13:02:07 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_check_all(t_init *game, t_cell elements)
{
	int	msg;

	msg = SUCCESS;
	if (ft_check_main_elements(elements) == FAILURE)
		msg = FAILURE;
	if (ft_check_cells(game->cell, elements) == FAILURE)
		msg = FAILURE;
	if (ft_map_shape(game) == FAILURE)
		msg = FAILURE;
	if (ft_check_borders(game) == FAILURE)
		msg = FAILURE;
	if (msg == FAILURE)
	{
		ft_printf("ERROR POSIBILITIES: \n\n📛There is a fake \
		char in the Matrix.\n📛There is a diferent object \
		in a cell.\n📛The map is not rectangular \
		(in this case).\n📛The walls are broken, check all '1' \
		in the matrix.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

void	ft_check_empty_line(t_init *game, char *line)
{
	t_map	*new;

	if (line[0] == '\n')
	{
		ft_printf("⛔ There is one or more empty lines in the file... ⛔");
		free(line);
		exit(FAILURE);
	}
	new = ft_add_line(line);
	ft_last_line(game, new);
	free(line);
}

int	ft_key_check(t_init *game)
{
	if (game->status_a[game->character.y - 1][game->character.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (1);
	if (game->status_a[game->character.y + 1][game->character.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (2);
	if (game->status_a[game->character.y][game->character.x - 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (3);
	if (game->status_a[game->character.y][game->character.x + 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (4);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (5);
	return (0);
}
