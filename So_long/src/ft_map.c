/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:36:12 by drosales          #+#    #+#             */
/*   Updated: 2024/08/30 19:56:39 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_init ft_init_game(t_init *start)
{
    start->mlx = NULL;
    start->size.x = 0;
    start->size.y = 0;
    start->character.x = 0;
    start->character.y = 0;
    start->result = 0;
    start->moves = 0;
    start->map = NULL;
    start->collect_done = 0;
    start->collect = 0;
    start->c_counter = 0;
    start->path = NULL;
    return (start);
}

int ft_init_map(char *map)
{
    t_init *game;

    game = malloc(sizeof (t_init));
    if (!game)
        return (1);
    game = ft_init_game(game);
    game = 
}