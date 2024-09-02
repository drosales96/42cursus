/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:30:56 by drosales          #+#    #+#             */
/*   Updated: 2024/09/02 09:40:37 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    right(t_elements *data)
{
    
}

int key_arrows(int key, t_elements *data)
{
    char    *move_p;
    int     msg;

    (void)data;
    msg = ESC_PUSH;
    if (key == ESC)
    {
        ft_free(data);
        return (msg);
    }
    else if (key == LEFT)
        ft_move_left(data);
    else if (key == RIGHT)
        ft_move_right(data);
    else if (key == UP)
        ft_move_up(data);
    else if (key == DOWN)
        ft_move_down(data);
    move_p = ft_itoa(data->pl_move);
    write(1, move_p, ft_strlen(move_p));
    if (move_p)
        free(move_p);
    ft_printf("\n");
    return (0);
}
