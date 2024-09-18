/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:34:29 by sternero          #+#    #+#             */
/*   Updated: 2024/09/17 09:19:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	return (SUCCESS);
}
