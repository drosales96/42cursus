/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:33:27 by drosales          #+#    #+#             */
/*   Updated: 2024/09/05 20:56:32 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int    ft_init_game(t_elements *data, char *map)
{
    if (!data || !data->map)
        exit (EXIT_FAILURE);
    data->pl_move = 0;
    ft_file_checker(map, data);
    ft_reading_map(map, data);
    ft_png_to_text(data);
    ft_init_text(data);
    data->mlx_window = mlx_init(WIDTH_W, HEIGHT_W, TITLE, true);
    ft_print_matrix(data);
    return (0);
}

int main(int ac, char **av)
{
    int             i;
    t_elements      *game;

    i = 0;
    if (ac != 2)
        return (ARG_ERROR);
    if (ac == 2)
    {
        game = ft_calloc(1, sizeof(t_elements));
        if (!game)
            return (ALLOC_ERROR);
        ft_init_game(game, av[i]);
        mlx_key_hook(game->mlx_window, key_arrows, game);
        mlx_loop(game->mlx);
        mlx_terminate(game->mlx);
    }
}