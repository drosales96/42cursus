/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:19:21 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 12:41:37 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_x(t_map *width)
{
	int	x;

	x = 0;
	while (width->map[x] != '\n')
		x++;
	return (x);
}

int	ft_map_y(t_map *height)
{
	int	y;

	y = 0;
	while (height)
	{
		y++;
		height = height->next;
	}
	return (y);
}

int	ft_check_main_elements(t_cell objects)
{
	if (objects.character != 1)
		ft_printf("⛔ There is no player in the map! ⛔");
	if (objects.collec < 1)
		ft_printf("⛔ You must put one or more collectibles in the map! ⛔");
	if (objects.exit != 1)
		ft_printf("⛔ There is no EXIT in the game, ridiculous... ⛔");
	return (SUCCESS);
}

t_map	*ft_add_line(char *line)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = ft_strdup(line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	if (!new->map)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	ft_last_line(t_init *game, t_map *new)
{
	t_map	*last;

	last = game->map;
	if (!last)
		game->map = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
