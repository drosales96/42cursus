/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:20:27 by drosales          #+#    #+#             */
/*   Updated: 2024/08/30 20:18:00 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_check_file_name(char *file)
{
    size_t i;

    i = ft_strlen(file);
    if (file[i - 4] != '.' || file[i - 3] != 'b' 
            || file[i - 2] != 'e' || file[i - 1] != 'r')
            return (1);
    return (0);
}

t_init **ft_check_elements(t_init **game, char element)
{
    if (element == 'C')
    {
        (*game)->cell.collect++;
        (*game)->collect++;
    }
    if (element == 'P')
        (*game)->cell.character++;
    if (element == 'E')
        (*game)->cell.exit++;
    return (game);
}

