/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cells_management_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:47:06 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 12:24:52 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

t_init	**ft_fill(char **stat, t_coord size, t_coord now, t_init **game)
{
	if (now.y < 0 || now.y >= size.y || now.x < 0 || now.x >= size.x
		|| stat[now.y][now.x] == '1' || stat[now.y][now.x] == 'F')
		return (game);
	if (stat[now.y][now.x] == 'E')
	{
		stat[now.y][now.x] = 'F';
		(*game)->cell.exit++;
		return (game);
	}
	game = ft_check_cell(game, stat[now.y][now.x]);
	stat[now.y][now.x] = 'F';
	game = ft_fill(stat, size, (t_coord){now.x - 1, now.y}, game);
	game = ft_fill(stat, size, (t_coord){now.x + 1, now.y}, game);
	game = ft_fill(stat, size, (t_coord){now.x, now.y - 1}, game);
	game = ft_fill(stat, size, (t_coord){now.x, now.y + 1}, game);
	return (game);
}

t_init	*ft_flood(t_init *game)
{
	game->cell.character = 0;
	game->cell.collec = 0;
	game->cell.exit = 0;
	game = *ft_fill(game->status_b, game->size, game->character, &game);
	return (game);
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

int	ft_check_cells(t_cell checked, t_cell objects)
{
	if (checked.character != objects.character)
		return (FAILURE);
	if (checked.collec != objects.collec)
		return (FAILURE);
	if (checked.exit != objects.exit)
		return (FAILURE);
	return (SUCCESS);
}
