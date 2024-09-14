/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 07:57:02 by sternero          #+#    #+#             */
/*   Updated: 2024/09/14 01:56:00 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_mlx_init(t_init *gm)
{
	gm = ft_find_character(gm);
	gm->mlx = mlx_init(gm->size.x * 64, gm->size.y * 64, "so_long", true);
	if (!gm || !gm->mlx)
	{
		ft_printf("⛔ MLX library isn't working... ⛔");
		ft_free(gm, 1);
		exit(FAILURE);
	}
	ft_init_txts(gm);
	ft_init_imgs(gm);
	ft_print_matrix(gm);
	gm->imgs.character = NULL;
	mlx_key_hook(gm->mlx, ft_key_press, gm);
	mlx_loop(gm->mlx);
}
