/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:31:25 by drosales          #+#    #+#             */
/*   Updated: 2024/08/31 19:04:19 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_free(t_elements *data)
{
    data->error = 1;
    if (data->map)
        free(data->map);
    if (data)
        free(data);
    exit(0);
}