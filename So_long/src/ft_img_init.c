/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:46:17 by drosales          #+#    #+#             */
/*   Updated: 2024/09/02 12:03:13 by drosales         ###   ########.fr       */
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
    data->pl = mlx_xpm_file_to_image(data->mlx, "assets/faced.xpm", &w, &h);
    data->pl = mlx_xpm_file_to_image(data->mlx, "assets/front.xpm", &w, &h);
    data->pl = mlx_xpm_file_to_image(data->mlx, "assets/left.xpm", &w, &h);
    data->pl = mlx_xpm_file_to_image(data->mlx, "assets/right.xpm", &w, &h);
}