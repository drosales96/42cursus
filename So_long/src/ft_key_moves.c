/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:30:56 by drosales          #+#    #+#             */
/*   Updated: 2024/09/04 12:16:07 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void ft_data_check(t_elements *data)
{
    if (!data)
    {
        ft_printf("Error");
        exit(EXIT_FAILURE);
    }
}

static void    ft_move_right(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
        i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i + data->width_len]))
    {
        data->moves++;
        if (data->map[i - data->width_len] == 'C')
            data->collect--;
        data->map[i] = '0';
        data->map[i - data->width_len] = 'P';
        if (data->player_control == 0)
        {
            data->player_P = data->pl_back;
            data->player_control = 1;
        }
        else
        {
            data->player_P = data->pl_move;
            data->player_control = 0;
        }
    }
    ft_print_matrix();
}
static void    ft_move_down(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
    i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i + data->width_len]))
    {
        data->moves++;
        if (data->map[i - data->width_len] == 'C')
            data->collect--;
        data->map[i] = '0';
        data->map[i - data->width_len] = 'P';
        if (data->player_control == 0)
        {
            data->player_P = data->pl_back;
            data->player_control = 1;
        }
        else
        {
            data->player_P = data->pl_move;
            data->player_control = 0;
        }
    }
    ft_print_matrix();
}

static void    ft_move_up(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
    i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i - data->width_len]))
    {
        data->moves++;
        if (data->map[i - data->width_len] == 'C')
            data->collect--;
        data->map[i] = '0';
        data->map[i - data->width_len] = 'P';
        if (data->player_control == 0)
        {
            data->player_P = data->pl_back;
            data->player_control = 1;
        }
        else
        {
            data->player_P = data->pl_move;
            data->player_control = 0;
        }
    }
    ft_print_matrix();
}

static void ft_move_left(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
    i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i - data->width_len]))
    {
        data->moves++;
        if (data->map[i - data->width_len] == 'C')
            data->collect--;
        data->map[i] = '0';
        data->map[i - data->width_len] = 'P';
        if (data->player_control == 0)
        {
            data->player_P = data->pl_back;
            data->player_control = 1;
        }
        else
        {
            data->player_P = data->pl_move;
            data->player_control = 0;
        }
    }
    ft_print_matrix();
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
