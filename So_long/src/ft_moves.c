/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:15:22 by sternero          #+#    #+#             */
/*   Updated: 2024/09/19 10:21:34 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_moves_counter(t_init *game)
{
	char	*counter;
	
	mlx_image_to_window(game->mlx, game->imgs.wall, 64, 1);
	counter = ft_itoa(game->moves);
	ft_printf("MOVES: %d\n", game->moves);
	mlx_put_string(game->mlx, "Moves: ", 20, 20);
	mlx_put_string(game->mlx, counter, 85, 20);
	free (counter);
}

void	ft_move_char_right(t_init *game, int y, int x)
{
	t_coord	coord;

	coord.y = y;
	coord.x = x;
	if (game->status_a[y][x + 1] == 'E' && game->c < game->collec)
		return ;
	if (game->status_a[y][x + 1] == 'C')
		game->c++;
	if (game->status_a[y][x + 1] == 'E')
		ft_printf("YOU HAVE WIN THE GAME ✅\n");
	if (game->status_a[y][x + 1] == 'E')
		mlx_close_window(game->mlx);
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y][x + 1] = 'P';
	game->counter++;
	game->course = 'R';
	game->walking = true;
	ft_moves_counter(game);
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
	if (game->status_a[y][x - 1] == 'E' && game->c < game->collec)
		return ;
	if (game->status_a[y][x - 1] == 'C')
		game->c++;
	if (game->status_a[y][x - 1] == 'E' && game->c == game->collec)
		ft_printf("YOU HAVE WON THE GAME ✅\n");
	if (game->status_a[y][x - 1] == 'E')
		mlx_close_window(game->mlx);
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y][x - 1] = 'P';
	game->counter++;
	game->course = 'L';
	game->walking = true;
	ft_moves_counter(game);
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
	if (game->status_a[y - 1][x] == 'E' && game->c < game->collec)
		return ;
	if (game->status_a[y - 1][x] == 'C')
		game->c++;
	if (game->status_a[y - 1][x] == 'E' && game->c == game->collec)
		ft_printf("YOU HAVE WIN THE GAME ✅\n");
	if (game->status_a[y - 1][x] == 'E')
		mlx_close_window(game->mlx);
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y - 1][x] = 'P';
	game->counter++;
	game->course = 'U';
	game->walking = true;
	ft_moves_counter(game);
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
	if (game->status_a[y + 1][x] == 'E' && game->c < game->collec)
		return ;
	if (game->status_a[y + 1][x] == 'C')
		game->c++;
	if (game->status_a[y + 1][x] == 'E' && game->c == game->collec)
		ft_printf("YOU HAVE WIN THE GAME ✅\n");
	if (game->status_a[y + 1][x] == 'E')
		mlx_close_window(game->mlx);
	game->moves++;
	game->status_a[y][x] = '0';
	game->status_a[y + 1][x] = 'P';
	game->counter++;
	game->course = 'D';
	game->walking = true;
	ft_moves_counter(game);
	ft_drawing_imgs(game, game->status_a[y][x], coord);
	coord.y++;
	game->walking = false;
	ft_drawing_imgs(game, game->status_a[y + 1][x], coord);
}
