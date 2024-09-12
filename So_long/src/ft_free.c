/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:56:18 by sternero          #+#    #+#             */
/*   Updated: 2024/09/12 18:09:15 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(t_init *game, int error)
{
	if (error == 2)
	{
		ft_free_stack(&game->map);
		free(game);
	}
	if (error == 1)
	{
		game->status_a = ft_free_status(game->status_a, game->size.y);
		ft_free_stack(&game->map);
		free(game);
	}
	if (error == 0)
	{
		game->status_a = ft_free_status(game->status_a, game->size.y);
		ft_free_stack(&game->map);
		ft_free_textures(&game);
		ft_free_images(&game);
		mlx_terminate(game->mlx);
		free(game);
	}
}

void	ft_free_stack(t_map **stack)
{
	t_map	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->map);
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_free_textures(t_init **game)
{
	mlx_delete_texture((*game)->txts.ocean);
	(*game)->txts.ocean = NULL;
	mlx_delete_texture((*game)->txts.wall);
	(*game)->txts.wall = NULL;
	mlx_delete_texture((*game)->txts.collec);
	(*game)->txts.collec = NULL;
	mlx_delete_texture((*game)->txts.exit_c);
	(*game)->txts.exit_c = NULL;
	mlx_delete_texture((*game)->txts.exit_o);
	(*game)->txts.exit_o = NULL;
	mlx_delete_texture((*game)->txts.ship);
	(*game)->txts.ship = NULL;
	mlx_delete_texture((*game)->txts.ship_u);
	(*game)->txts.ship_u = NULL;
	mlx_delete_texture((*game)->txts.ship_d);
	(*game)->txts.ship_d = NULL;
	mlx_delete_texture((*game)->txts.ship_l);
	(*game)->txts.ship_l = NULL;
	mlx_delete_texture((*game)->txts.ship_r);
	(*game)->txts.ship_r = NULL;
	mlx_delete_texture((*game)->txts.npc);
	(*game)->txts.npc = NULL;
}

void	ft_free_images(t_init **game)
{
	mlx_delete_image((*game)->mlx, (*game)->imgs.ocean);
	(*game)->imgs.ocean = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.wall);
	(*game)->imgs.wall = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.collec);
	(*game)->imgs.collec = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.exit_c);
	(*game)->imgs.exit_c = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.exit_o);
	(*game)->imgs.exit_o = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.ship);
	(*game)->imgs.ship = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.ship_u);
	(*game)->imgs.ship_u = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.ship_d);
	(*game)->imgs.ship_d = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.ship_l);
	(*game)->imgs.ship_l = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.ship_r);
	(*game)->imgs.ship_r = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.npc);
	(*game)->imgs.npc = NULL;
}

char	**ft_free_status(char **status, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(status[i]);
		status[i] = NULL;
		i++;
	}
	return (status);
}