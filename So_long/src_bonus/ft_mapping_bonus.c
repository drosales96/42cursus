/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:19:59 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 10:58:21 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_start_map(char *path)
{
	t_init	*game;

	game = ft_calloc(sizeof(t_init), 1);
	if (!game)
		return (FAILURE);
	game = ft_initialize_game(game);
	game->path = path;
	if (ft_map(&game) == 1)
		return (FAILURE);
	game = ft_find_character(game);
	game = ft_flood(game);
	game->status_b = ft_free_status(game->status_b, game->size.y);
	if (ft_check_all(game, ft_count_obj(game->map)) == FAILURE)
	{
		ft_free(game, 1);
		return (FAILURE);
	}
	ft_mlx_init(game);
	ft_free(game, 0);
	return (SUCCESS);
}

t_map	*ft_map_init(t_init *game)
{
	char	*line;
	int		fd;

	fd = open(game->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(ERR_MAP);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_check_empty_line(game, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (game->map);
}

int	ft_checking_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if ((file[len - 4] != '.' || file[len - 3] != 'b'
			|| file[len -2] != 'e' || file[len -1] != 'r'))
	{
		ft_printf("⛔ Are you sure that the file ends in '.ber'?...\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
int	ft_map_shape(t_init *game)
{
	int	i;
	int	j;
	int	l_size;

	l_size = 0;
	while (game->status_a[0][l_size] != '\n' && game->status_a[0][l_size] != '\0')
		l_size++;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->status_a[j][i] != '\n' && game->status_a[j][i] != '\0')
		{
			if (game->status_a[j][i] != '0' && game->status_a[j][i] != WALL
				&& game->status_a[j][i] != 'P' && game->status_a[j][i] != 'C'
				&& game->status_a[j][i] != EXIT && game->status_a[j][i] != ENEMY)
				return (FAILURE);
			i++;
		}
		if (i != l_size)
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	ft_check_borders(t_init *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->status_a[j][i] != '\n' && game->status_a[j][i] != '\0')
		{
			if ((j == 0 || j == game->size.y - 1 || i == 0 || i == game->size.x - 1)
				&& game->status_a[j][i] != WALL)
				return (FAILURE);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}