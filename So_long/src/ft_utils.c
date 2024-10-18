/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:46:28 by drosales          #+#    #+#             */
/*   Updated: 2024/10/18 12:46:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		ft_printf("📛 Something wrong with the Matrix!...\n");
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

t_init	**ft_check_cell(t_init	**game, char check)
{
	if (check == 'C')
	{
		(*game)->cell.collec++;
		(*game)->collec++;
	}
	if (check == 'P')
		(*game)->cell.character++;
	if (check == 'E')
		(*game)->cell.exit++;
	return (game);
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

int	ft_check_cells(t_cell checked, t_cell elements)
{
	if (checked.character != elements.character)
		return (FAILURE);
	if (checked.collec != elements.collec)
		return (FAILURE);
	if (checked.exit != elements.exit)
		return (FAILURE);
	return (SUCCESS);
}
