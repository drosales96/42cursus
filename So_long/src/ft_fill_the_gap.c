/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_gap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:02:22 by drosales          #+#    #+#             */
/*   Updated: 2024/09/06 09:59:38 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void    ft_fill_the_gap(char element, int index, t_elements *data)
{
    int rows;
    int cols;

    rows = (index % data->width_len) * 64;
    cols = (index / data->width_len) * 64;
    if (data->error == 0) // SI NO HAY ERRORES EN LA MATRIZ, NI EN NIGÚN CASO
    {
        if (element == 'P')
            mlx_image_to_window(data->mlx, data->player, rows, cols);
        else if (element == 'C')
            mlx_image_to_window(data->mlx, data->collec, rows, cols);
        else if (element == '1')
            mlx_image_to_window(data->mlx, data->limit_element, rows, cols);
        else if (element == '0')
            mlx_image_to_window(data->mlx, data->background, rows, cols);
        else if (element == 'X')
            mlx_image_to_window(data->mlx, data->npc, rows, cols);
        else if (element == 'E')
            mlx_image_to_window(data->mlx, data->exit, rows, cols);
    }
}

/* COLOCAMOS TODOS LOS ELEMENTOS MOVIENDONOS POR EL PUNTERO QUE SEÑALA AL MAPA QUE ESTA EN FORMATO UNILINEAL */

void ft_print_matrix(t_elements *data)
{
    int i;

    i = 0;
    while (data->map[i])
    {
        if (data->map[i] == '\n')
            i++;
        if (data->map[i] != 'P'&& data->map[i] != 'C'&& data->map[i] != '1'&& data->map[i] != '0'&& data->map[i] != 'X'&& data->map[i] != 'E')
            exit(0);
        if (data->map[i] == 'P')
            ft_fill_the_gap('P', i, data);
        else if (data->map[i] == 'C')
            ft_fill_the_gap('C', i, data);
        else if (data->map[i] == '1')
            ft_fill_the_gap('1', i, data);
        else if (data->map[i] == '0')
            ft_fill_the_gap('0', i, data);
        else if (data->map[i] == 'X')
            ft_fill_the_gap('X', i, data);
        else if (data->map[i] == 'E')
            ft_fill_the_gap('E', i, data);
    }
    i++;
}