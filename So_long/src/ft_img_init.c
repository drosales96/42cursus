/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:46:17 by drosales          #+#    #+#             */
/*   Updated: 2024/09/04 09:30:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_png_to_text(t_elements *data)
{
    data->background = mlx_load_png("/assets/grass.png");
    data->limit_element = mlx_load_png("/assets/arbol.png");
    data->exit = mlx_load_png("/assets/exit.png");
    data->npc = mlx_load_png("/assets/snorlax.png");
    data->collec = mlx_load_png("/assets/pokeball.png");
    data->player_P = mlx_load_png("/assets/front_ash.png");
    data->player = mlx_load_png("/assets/front_ash.png");
    data->pl_move = mlx_load_png("/assets/down_mv.png");
    data->pl_back = mlx_load_png("/assets/back_ash.png");
    data->pl_back_mv = mlx_load_png("/assets/up_move.png");
    data->pl_left = mlx_load_png("/assets/left_ash.png");
    data->pl_left_mv = mlx_load_png("/assets/left_mv.png");
    data->pl_right = mlx_load_png("/assets/right_ash.png");
    data->pl_right_move = mlx_load_png("/assets/right_mv.png");
    if (!data->background || !data->limit_element || !data->exit || !data->npc || !data->collec || !data->player_P || !data->player || !data->pl_move || !data->pl_back || !data->pl_back_mv || !data->pl_left || !data->pl_left_mv || !data->pl_right || !data->pl_right_move)
    {
        ft_printf("⛔ Error due matrix elements, Please push ESC and restart the game!");
        ft_free(data);
        exit(EXIT_FAILURE);
    }
}

void    ft_init_text(t_elements *data)
{
    if (!data)
    {
        ft_printf("⛔ Error: mlx no inicializado correctamente.");
        exit(EXIT_FAILURE);
    }
    data->background = mlx_texture_to_image(data->mlx, data->background);
    data->limit_element = mlx_texture_to_image(data->mlx, data->limit_element);
    data->exit = mlx_texture_to_image(data->mlx, data->exit);
    data->npc = mlx_texture_to_image(data->mlx, data->npc);
    data->collec = mlx_texture_to_image(data->mlx, data->collec);
    data->player_P = mlx_texture_to_image(data->mlx, data->player_P);
    data->player = mlx_texture_to_image(data->mlx, data->player);
    data->pl_move = mlx_texture_to_image(data->mlx, data->pl_move);
    data->pl_back = mlx_texture_to_image(data->mlx, data->pl_back);
    data->pl_back_mv = mlx_texture_to_image(data->mlx, data->pl_back_mv);
    data->pl_left = mlx_texture_to_image(data->mlx, data->pl_left);
    data->pl_left_mv = mlx_texture_to_image(data->mlx, data->pl_left_mv);
    data->pl_right = mlx_texture_to_image(data->mlx, data->pl_right);
    data->pl_right_move = mlx_texture_to_image(data->mlx, data->pl_right_move);
}