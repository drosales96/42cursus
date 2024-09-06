/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:30:56 by drosales          #+#    #+#             */
/*   Updated: 2024/09/06 11:09:23 by drosales         ###   ########.fr       */
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
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i + 1]))
    {
        data->moves++;
        if (data->map[i + data->width_len] == 'C')
            data->collect--;
        data->map[i] = '0';
        data->map[i + data->width_len] = 'P';
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
    ft_print_matrix(data);
}
static void    ft_move_down(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
    i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i + 1]))
    {
        data->moves++;
        if (data->map[i + data->width_len] == 'C')
            data->collect--;
        data->map[i] = '0';
        data->map[i + data->width_len] = 'P';
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
    ft_print_matrix(data);
}

static void    ft_move_up(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
    i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i + 1]))
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
    ft_print_matrix(data);
}

static void ft_move_left(t_elements *data)
{
    int i;

    i = 0;
    ft_data_check(data);
    while (data->map[i] != 'P')
    i++;
    if (data->map[i] != '1' && !ft_final_msg_check(data, data->map[i + 1]))
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
    ft_print_matrix(data);
}

void key_arrows(struct mlx_key_data keydata, void *param)
{
    t_elements  *data;
    char        *move_p;

    data = (t_elements *)param;
    if (keydata.key == LEFT)
        ft_move_left(data);
    else if (keydata.key == RIGHT)
        ft_move_right(data);
    else if (keydata.key == UP)
        ft_move_up(data);
    else if (keydata.key == DOWN)
        ft_move_down(data);
    move_p = ft_itoa(data->moves);
    if (move_p)
    {
        write(1, move_p, ft_strlen(move_p));
        free(move_p);
        ft_printf("\n");
    }
    else
        ft_printf("ERROR: Moves haven't been processed correctly!");
}

/* 

INFO: Funcionamiento de los movimientos.

map.ber:

111111111111
100P00000001
100C001000E1
111111111111

Imaginemos que usamos ft_move_down 'S':

En primer lugar vamos a recorrer el mapa unilineal (versión) y mientas no
sea la 'P' incrementamos por el string hasta topar con ella.

Ahora vamos a seguir comprobando y en segundo lugar, verificamos que haya
contenido y si hubiera algún error lo manejaría ft_check_data. En este ca-
so como hay elementos, lo primero que haremos será verificar en el mapa en
formato unilineal. que lo que itere sea diferente a '1' (WALL) y que no sea
el final del juego. Siendo así aumentamos el contador 'moves' para contabi-
lizar un movimiento, y después mediante la operación [i - data->widht_len], nos vamos a posicionar en la casilla del array que necesitamos pero localizando-
la en el formato unilineal. Graficamente vamos asi:

UNILINEAL:

i = 0;
111111111111\n100P00000001\n100C001000E1\n111111111111
i = 18
OPERACIÓN = [17 + 12] = 29
POSICIÓN PARA 'P' = CHAR Nº 29

Ahora lo que haremo será que si es una 'C' restaremos un coleccionable, y si
no fuera una 'C' pues pasamos a la siguiente línea de código. Así que pase
lo que pase lo siguiente será poner la casilla de la que partíamos con un '0'
puesto que ya nos hemos movido de forma abstracta. Desṕues mediante la opera-
ción anterior como ya sabemos que está en la posición 29, pues le damos el
valor de 'P' ya que nuestro jugador se ha movido a esa casilla.

*/
