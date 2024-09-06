/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:21:59 by drosales          #+#    #+#             */
/*   Updated: 2024/09/06 12:34:48 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#include <string.h> // Para strlen

void ft_file_checker(char *file)
{
    int i;

    if (!file || (i = ft_strlen(file)) < 4)
    {
        return;
    }
    if (file[i - 4] == '.' && file[i - 3] == 'b' && file[i - 2] == 'e' && file[i - 1] == 'r')
    {
        return;
    }
    else
    {
        return ;
    }
}
