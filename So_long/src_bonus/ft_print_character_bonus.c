/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:27:50 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 12:25:44 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_char_to_up(t_init *game, t_coord p, int step)
{
	mlx_delete_image(game->mlx, game->imgs.character);
	if (step % 2 == 0 && game->imgs.character_u != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_u,
			p.x * 64, p.y * 64);
	else if (game->imgs.character_u != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_u,
			p.x * 64, p.y * 64);
}

void	ft_char_to_down(t_init *game, t_coord p, int step)
{
	mlx_delete_image(game->mlx, game->imgs.character);
	if (step % 2 == 0 && game->imgs.character_d != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_d,
			p.x * 64, p.y * 64);
	else if (game->imgs.character_d != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_d,
			p.x * 64, p.y * 64);
}

void	ft_char_to_right(t_init *game, t_coord p, int step)
{
	mlx_delete_image(game->mlx, game->imgs.character);
	if (step % 2 == 0 && game->imgs.character_r != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_r,
			p.x * 64, p.y * 64);
	else if (game->imgs.character_r != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_r,
			p.x * 64, p.y * 64);
}

void	ft_char_to_left(t_init *game, t_coord p, int step)
{
	mlx_delete_image(game->mlx, game->imgs.character);
	if (step % 2 == 0 && game->imgs.character_l != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_l,
			p.x * 64, p.y * 64);
	else if (game->imgs.character_l != NULL)
		mlx_image_to_window(game->mlx, game->imgs.character_l,
			p.x * 64, p.y * 64);
}
