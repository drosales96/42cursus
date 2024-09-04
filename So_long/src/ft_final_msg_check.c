/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:45:22 by drosales          #+#    #+#             */
/*   Updated: 2024/09/04 09:47:40 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_final_msg_check(t_elements *data, char c)
{
    if (data->collect == 0 && c == 'E')
    {
        ft_printf("You have win the game! 💯​");
        ft_free(data);
    }
    if (data->collect != 0 && c == 'E')
    {
        ft_printf("Come on, you need to take all collectibles! ❌​");
        ft_free(data);
    }
    return (0);
}