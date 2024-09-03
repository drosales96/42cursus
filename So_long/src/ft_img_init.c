/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:46:17 by drosales          #+#    #+#             */
/*   Updated: 2024/09/03 09:34:37 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_img_init(t_elements *data)
{
    int w;
    int h;

    w = 50;
    h = 50;
    data->x = (ft_strlen(data->map) / data->width_len + 1) * 50;
    data->y = (data->width_len - 1) * 50;
    data->player_P = mlx_png_file_to_image(data->mlx, "assets/front_ash.png", &w, &h);
    data->pl_back = mlx_png_file_to_image(data->mlx, "assets/back_ash.png",&w, &h);
    data->pl_left = mlx_png_file_to_image(data->mlx, "assets/left_ash.png",&w, &h);
    data->pl_right = mlx_png_file_to_image(data->mlx, "assets/right_ash.png",&w, &h);
    data->player = mlx_png_file_to_image(data->mlx, "assets/front_ash.png",&w, &h);
    data->pl_back_mv = mlx_png_file_to_image(data->mlx, "assets/up_move.png", &w, &h);
    data->pl_left_mv = mlx_png_file_to_image(data->mlx, "assets/left_mv.png", &w, &h);
    data->pl_right_move = mlx_png_file_to_image(data->mlx, "assets/right_mv.png", &w, &h);
    data->pl_move = mlx_png_file_to_image(data->mlx, "assets/down_mv.png", &w, &h);
    data->background = mlx_png_file_to_image(data->mlx, "assets/grass.png",&w, &h);
    data->collec = mlx_png_file_to_image(data->mlx, "assets/pokeball.png",&w, &h);
    data->npc = mlx_png_file_to_image(data->mlx, "assets/snorlax.png", &w, &h);
    data->exit = mlx_png_file_to_image(data->mlx, "assets/exit.png",&w, &h);
    data->limit_element = mlx_png_file_to_image(data->mlx, "assets/arbol.png", &w, &h);
}