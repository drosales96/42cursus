/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:44:49 by drosales          #+#    #+#             */
/*   Updated: 2024/09/14 02:23:40 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_drawing_imgs(t_init *game, char img, t_coord p)
{
	if (img == '1' && game->imgs.wall != NULL)
		mlx_image_to_window(game->mlx, game->imgs.wall, p.x * 64, p.y * 64);
	if (img != '1' && game->imgs.floor != NULL)
		mlx_image_to_window(game->mlx, game->imgs.floor, p.x * 64, p.y * 64);
	if (img == 'P')
	{
		ft_drawing_char(game, p);
		return ;
	}
	if (img == 'X' && game->imgs.npc != NULL)
		mlx_image_to_window(game->mlx, game->imgs.npc, p.x * 64, p.y * 64);
	if (img == 'C' && game->imgs.collec != NULL)
		mlx_image_to_window(game->mlx, game->imgs.collec, p.x * 64, p.y * 64);
	if (img == 'E' && game->imgs.exit_c != NULL)
		mlx_image_to_window(game->mlx, game->imgs.exit_c, p.x * 64, p.y * 64);
}

void	ft_drawing_char(t_init *game, t_coord p)
{
	if (game->course == 'U' && game->counter > 0)
		ft_char_to_up(game, p, game->counter);
	else if (game->course == 'D' && game->counter > 0)
		ft_char_to_down(game, p, game->counter);
	else if (game->course == 'R' && game->counter > 0)
		ft_char_to_right(game, p, game->counter);
	else if (game->course == 'L' && game->counter > 0)
		ft_char_to_left(game, p, game->counter);
	else
		mlx_image_to_window(game->mlx, game->imgs.character, p.x * 64, p.y * 64);
}
void	ft_print_matrix(t_init *game)
{
	t_coord	coord;
	int		j;
	int		i;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->status_a[j][i] != '\n' && game->status_a[j][i] != '\0')
		{
			coord.x = i;
			coord.y = j;
			ft_drawing_imgs(game, game->status_a[j][i], coord);
			i++;
		}
		j++;
	}
	ft_drawing_char(game, game->character);
}

