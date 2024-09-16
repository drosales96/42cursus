/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_materials.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:17:28 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 09:13:56 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_init	*ft_find_character(t_init *character)
{
	int		i;
	int		j;

	j = 1;
	character->character.x = 0;
	character->character.y = 0;
	while (j < character->size.y)
	{
		i = 1;
		while (character->status_a[j][i] != '\n')
		{
			if (character->status_a[j][i] == PLAYER)
			{
				character->character.x = i;
				character->character.y = j;
				return (character);
			}
			i++;
		}
		j++;
	}
	return (character);
}

void	ft_objs_init(t_cell *obj)
{
	obj->character = 0;
	obj->collec = 0;
	obj->exit = 0;
}

t_cell	ft_count_obj(t_map *map)
{
	t_cell	obj;
	int		i;

	ft_objs_init(&obj);
	while (map)
	{
		i = 0;
		while (map->map[i])
		{
			if (map->map[i] == PLAYER)
				obj.character++;
			if (map->map[i] == COLLECT)
				obj.collec++;
			if (map->map[i] == EXIT)
				obj.exit++;
			i++;
		}
		map = map->next;
	}
	if (obj.character != 1 || obj.exit != 1)
	{
		ft_printf("⛔ There is more than one element of character or exit...\n");
		exit (EXIT_FAILURE);
	}
	return (obj);
}


