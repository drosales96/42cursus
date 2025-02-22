/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cells_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:45:17 by drosales          #+#    #+#             */
/*   Updated: 2024/10/18 12:45:21 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

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
