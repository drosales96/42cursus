/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:26:32 by drosales          #+#    #+#             */
/*   Updated: 2024/07/24 11:43:00 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack **stack)
{
    if ((*stack) == NULL || (*stack)->next == NULL)
        return (NULL);
    while ((*stack)->next != NULL)
    {
        if (((*stack)->index) > ((*stack)->next->index))
            return (1); /*TRUE*/
        else
            break;
    }
    return (0);
}