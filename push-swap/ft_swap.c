/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:02:25 by drosales          #+#    #+#             */
/*   Updated: 2024/07/23 11:30:56 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list **stack, int a)
{
    int     temp;
    t_list  *node;
    
    node = stack;
    temp = node->nb;
    node->nb = node->next->nb;
    node->next->nb = temp; /*MODIFICAMOS EL NÚMERO*/
    temp = node->index;
    node->index = node->next->index;
    node->next->index = temp;/*MODIFICAMOS SU ÍNDICE*/
    if (a)
        write(1, "sa\n", 2);
}

void    sb(t_list **stack, int a)
{
    int     temp;
    t_list  *node;

    node = stack;
    temp = node->nb;
    node->nb = node->next->nb;
    node->next->nb = temp;/*MODIFICAMOS EL NÚMERO*/
    temp = node->index;
    node->index = node->next->index;
    node->next->index = temp;/*MODIFICAMOS SU ÍNDICE*/
    if (a)
        write(1, "sb\n", 2);
}
