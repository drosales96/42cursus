/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:15:22 by sternero          #+#    #+#             */
/*   Updated: 2024/09/12 17:38:38 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_char_right(t_init *game, int y, int x)
{
	t_coord	coord;

	coord.y = y;
	coord.x = x;
	if (game->status_a[y][x + 1] == 'C')
		game->c++;
	else if (game->status_a[y][x + 1] == 'E' && game->c == game->collec)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->status_a[y][x + 1] == 'E')
		return ;
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y][x + 1] = 'P';
	game->counter++;
	game->course = 'R';
	game->walking = true;
	ft_printf("Total moves: %s%d\n%s", GREEN, game->moves, RESET);
	ft_drawing_imgs(game, game->status_a[y][x], coord);
	coord.x++;
	game->walking = false;
	ft_drawing_imgs(game, game->status_a[y][x + 1], coord);
}

void	ft_move_char_left(t_init *game, int y, int x)
{
	t_coord	coord;

	coord.y = y;
	coord.x = x;
	if (game->status_a[y][x - 1] == 'C')
		game->c++;
	else if (game->status_a[y][x - 1] == 'E' && game->c == game->collec)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->status_a[y][x - 1] == 'E')
		return ;
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y][x - 1] = 'P';
	game->counter++;
	game->course = 'L';
	game->walking = true;
	ft_printf("Total moves: %s%d\n%s", GREEN, game->moves, RESET);
	ft_drawing_imgs(game, game->status_a[y][x], coord);
	coord.x--;
	game->walking = false;
	ft_drawing_imgs(game, game->status_a[y][x - 1], coord);
}

void	ft_move_char_up(t_init *game, int y, int x)
{
	t_coord	coord;

	coord.y = y;
	coord.x = x;
	if (game->status_a[y - 1][x] == 'C')
		game->c++;
	else if (game->status_a[y - 1][x] == 'E' && game->c == game->collec)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->status_a[y - 1][x] == 'E')
		return ;
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y - 1][x] = 'P';
	game->counter++;
	game->course = 'U';
	game->walking = true;
	ft_printf("Total moves: %s%d\n%s", GREEN, game->moves, RESET);
	ft_drawing_imgs(game, game->status_a[y][x], coord);
	coord.y--;
	game->walking = false;
	ft_drawing_imgs(game, game->status_a[y - 1][x], coord);
}

void	ft_move_char_down(t_init *game, int y, int x)
{
	t_coord	coord;

	coord.y = y;
	coord.x = x;
	if (game->status_a[y + 1][x] == 'C')
		game->c++;
	else if (game->status_a[y + 1][x] == 'E' && game->c == game->collec)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->status_a[y + 1][x] == 'E')
		return ;
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y + 1][x] = 'P';
	game->counter++;
	game->course = 'D';
	game->walking = true;
	ft_printf("Total moves: %s%d\n%s", GREEN, game->moves, RESET);
	ft_drawing_imgs(game, game->status_a[y][x], coord);
	coord.y++;
	game->walking = false;
	ft_drawing_imgs(game, game->status_a[y + 1][x], coord);
}
