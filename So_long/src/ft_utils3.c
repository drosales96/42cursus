/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:15:29 by drosales          #+#    #+#             */
/*   Updated: 2024/09/17 11:51:16 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**ft_status_map(t_init *game)
{
	t_map	*tmp;
	char	**status;
	int		i;

	i = 0;
	tmp = game->map;
	status = malloc(sizeof(char *) * (game->size.y + 1));
	if (!status)
	{
		free (status);
		return (NULL);
	}
	while (game->map)
	{
		status[i] = ft_strdup(game->map->map);
		if (!status[i++])
		{
			free(status);
			return (NULL);
		}
		game->map = game->map->next;
	}
	game->map = tmp;
	status[i] = NULL;
	return (status);
}

void	ft_key_press(struct mlx_key_data key_data, void *date)
{
	t_init	*game;

	game = date;
	game = ft_find_character(game);
	if (key_data.key == MLX_KEY_UP && ft_key_check(game) == 1)
		ft_move_char_up(game, game->character.y, game->character.x);
	if (key_data.key == MLX_KEY_DOWN && ft_key_check(game) == 2)
		ft_move_char_down(game, game->character.y, game->character.x);
	if (key_data.key == MLX_KEY_LEFT && ft_key_check(game) == 3)
		ft_move_char_left(game, game->character.y, game->character.x);
	if (key_data.key == MLX_KEY_RIGHT && ft_key_check(game) == 4)
		ft_move_char_right(game, game->character.y, game->character.x);
	if (key_data.key == MLX_KEY_ESCAPE && ft_key_check(game) == 5)
	{
		mlx_close_window(game->mlx);
		return ;
	}
}

int	ft_map(t_init **game)
{
	t_init	*tmp;

	tmp = *game;
	tmp->map = ft_map_init(tmp);
	if (!tmp->map)
	{
		free(tmp);
		return (1);
	}
	tmp->size.x = ft_map_x(tmp->map);
	tmp->size.y = ft_map_y(tmp->map);
	tmp->status_a = ft_status_map(tmp);
	if (!tmp->status_a)
	{
		free(tmp);
		return (FAILURE);
	}
	tmp->status_b = ft_status_map(tmp);
	if (!tmp->status_b)
	{
		free(tmp);
		return (FAILURE);
	}
	*game = tmp;
	return (SUCCESS);
}
