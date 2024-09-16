/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:30:52 by drosales          #+#    #+#             */
/*   Updated: 2024/09/16 12:59:20 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

t_init	*ft_initialize_game(t_init *init)
{
	init->mlx = NULL;
	init->path = NULL;
	init->map = NULL;
	init->status_a = NULL;
	init->status_b = 0;
	init->character.x = 0;
	init->character.y = 0;
	init->size.x = 0;
	init->size.y = 0;
	init->moves = 0;
	init->c = 0;
	init->counter = 0;
	init->collec = 0;
	init->flag = 0;
	return (init);
}

void	ft_init_txts(t_init *game)
{
	game->txts.wall = mlx_load_png("./assets/arbol.png");
	game->txts.floor = mlx_load_png("./assets/floor.png");
	game->txts.character = mlx_load_png("./assets/a_pos.png");
	game->txts.character_u = mlx_load_png("./assets/as_up.png");
	game->txts.character_d = mlx_load_png("./assets/a_down.png");
	game->txts.character_l = mlx_load_png("./assets/a_left.png");
	game->txts.character_r = mlx_load_png("./assets/a_right.png");
	game->txts.npc = mlx_load_png("./assets/enemy.png");
	game->txts.collec = mlx_load_png("./assets/pokeball.png");
	game->txts.exit_c = mlx_load_png("./assets/exit.png");
	game->txts.exit_o = mlx_load_png("./assets/exit.png");
	if (!game->txts.wall || !game->txts.floor || !game->txts.character
		|| !game->txts.character_u || !game->txts.character_d
		|| !game->txts.character_l || !game->txts.character_r
		|| !game->txts.npc || !game->txts.collec
		|| !game->txts.exit_c || !game->txts.exit_o)
	{
		ft_printf("💀 We are not processing the textures 💀\n");
		ft_free(game, 1);
		exit(FAILURE);
	}
}

void	ft_init_imgs(t_init *game)
{
	game->imgs.wall = mlx_texture_to_image(game->mlx, game->txts.wall);
	game->imgs.floor = mlx_texture_to_image(game->mlx, game->txts.floor);
	game->imgs.character = mlx_texture_to_image(game->mlx, \
	game->txts.character);
	game->imgs.character_d = mlx_texture_to_image(game->mlx, \
	game->txts.character_d);
	game->imgs.character_l = mlx_texture_to_image(game->mlx, \
	game->txts.character_l);
	game->imgs.character_r = mlx_texture_to_image(game->mlx, \
	game->txts.character_r);
	game->imgs.character_u = mlx_texture_to_image(game->mlx, \
	game->txts.character_u);
	game->imgs.npc = mlx_texture_to_image(game->mlx, game->txts.npc);
	game->imgs.collec = mlx_texture_to_image(game->mlx, game->txts.collec);
	game->imgs.exit_c = mlx_texture_to_image(game->mlx, game->txts.exit_c);
	game->imgs.exit_o = mlx_texture_to_image(game->mlx, game->txts.exit_o);
}
