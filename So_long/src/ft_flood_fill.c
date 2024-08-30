/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:57:55 by drosales          #+#    #+#             */
/*   Updated: 2024/08/30 20:25:00 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_elements  **ft_fill(char **tab, t_matrix size, t_matrix cell, t_init **game)
{
    if (cell < 0 || cell < 0 || cell >= size.y || cell >= size.x
        ||tab[cell.y][cell.x] == 'F' || tab[cell.y][cell.x] == 1)
        return (game);
    if (tab[cell.y][cell.x] == 'E')
    {
        tab[cell.y][cell.x] = 'F';
        (*game)->cell.exit++;
        return (game);
    }
    game = ft_check_elements(game, tab[cell.y][cell.x]);
    tab[cell.y][cell.x] = 'F';
    game = ft_fill(tab, size, (t_matrix){cell.x - 1, cell.y}, game);
    game = ft_fill(tab, size, (t_matrix){cell.x + 1, cell.y}, game);
    game = ft_fill(tab, size, (t_matrix){cell.x, cell.y - 1}, game);
    game = ft_fill(tab, size, (t_matrix){cell.x, cell.y + 1}, game);
    return (game);
}

t_init *ft_flood(t_init *game)
{
    game->cell.character = 0;
    game->cell.collect = 0;
    game->cell.exit = 0;
    game = *ft_fill(game->)
}
