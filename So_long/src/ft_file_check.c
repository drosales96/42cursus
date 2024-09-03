/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:21:59 by drosales          #+#    #+#             */
/*   Updated: 2024/09/03 08:50:56 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_file_checker(char *map, t_elements *data)
{
    int i;

    i = 0;
    while (map[i] != '\0')
    {
        if (map[i - 4] != '.')
            return (FILE_ERROR);
        else if (map[i - 3] != 'b')
            return (FILE_ERROR);
        else if (map[i - 2] != 'e')
            return (FILE_ERROR);
        else if (map[i - 1] != 'r')
            return (FILE_ERROR);
    }
    return (0);
}