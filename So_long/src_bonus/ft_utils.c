/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:48:54 by sternero          #+#    #+#             */
/*   Updated: 2024/09/12 17:47:38 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_all(t_init *game, t_cell objects)
{
	int	msg;

	msg = SUCCESS;
	if (ft_check_main_elements(objects) == FAILURE)
		msg = FAILURE;
	if (ft_check_cells(game->cell, objects) == FAILURE)
		msg = FAILURE;
	if (ft_map_shape(game) == FAILURE)
		msg = FAILURE;
	if (ft_check_borders(game) == FAILURE)
		msg = FAILURE;
	if (msg == FAILURE)
	{
		ft_printf("⛔ The map or some objects are wrong... ⛔");
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
		(*game)->cell.ship++;
	if (check == 'E')
		(*game)->cell.exit++;
	return (game);
}

int	ft_key_check(t_init *game)
{
	if (game->status_a[game->ship.y - 1][game->ship.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (1);
	if (game->status_a[game->ship.y + 1][game->ship.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (2);
	if (game->status_a[game->ship.y][game->ship.x - 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (3);
	if (game->status_a[game->ship.y][game->ship.x + 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (4);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (5);
	return (0);
}

int	ft_check_cells(t_cell checked, t_cell objects)
{
	if (checked.ship != objects.ship)
		return (FAILURE);
	if (checked.collec != objects.collec)
		return (FAILURE);
	if (checked.exit != objects.exit)
		return (FAILURE);
	return (SUCCESS);
}