/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 07:57:02 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 11:00:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_mlx_init(t_init *gm)
{
	gm = ft_find_character(gm);
	gm->mlx = mlx_init(gm->size.x * 64, gm->size.y * 64, "so_long", true);
	if (!gm || !gm->mlx)
	{
		exit(FAILURE);
		ft_printf("⛔ MLX library isn't working... ⛔");
		ft_free(gm, 1);
	}
	ft_init_txts(gm);
	ft_init_imgs(gm);
	ft_print_matrix(gm);
	gm->imgs.character = NULL;
	mlx_key_hook(gm->mlx, ft_key_press, gm);
	mlx_loop(gm->mlx);
}
