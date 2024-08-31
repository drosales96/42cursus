/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:33:27 by drosales          #+#    #+#             */
/*   Updated: 2024/08/31 19:53:34 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_init_game(t_elements *data, char *map)
{
    data->pl_move = 0;
    ft_file_checker(map, data);
    ft_reading_map(map, data);
    /*LO SIGUIENTE SERÍA CARGAR LAS IMAGENES DEL JUEGO*/
    /*DESPUÉS CREAREMOS LA VENTANA*/
    /*POR ULTIMO TOCARÍA PRINTAR EL MAPA COMPLETO*/
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
        /*MLX KEY HOOK (TECLAS DE JUEGO)*/
        /*MLX HOOK VENTANA*/
        /*BUCLE DE LA LIBRERIA*/
        /*LIBERACIÓN DE ALLOCS*/
        /*RETORNO*/
    }
}