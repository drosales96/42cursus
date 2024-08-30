/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:54:41 by drosales          #+#    #+#             */
/*   Updated: 2024/08/30 19:34:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int ac, char **av)
{
    int	i;

	i = 0;
	if (ac != 2)
		return ;
	if (ac == 2)
	{
		if (ft_check_file_name(av[1]) == 1)
			return (FILE_ERROR);
		if (ft_check_file_name(av[1]) == 0)
			ft_split();
	}
}