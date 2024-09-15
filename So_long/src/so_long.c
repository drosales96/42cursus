/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:34:29 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 00:21:17 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("⛔ Needed two arguments... ⛔");
		return (FAILURE);
	}
	if (argc == 2)
	{
		if (ft_checking_file(argv[1]) == FAILURE)
			return (FAILURE);
		i = ft_start_map(argv[1]);
		if (i == 1)
			return (FAILURE);
	}
	ft_printf("YOU HAVE WIN THE GAME ✅\n");
	return (SUCCESS);
}
