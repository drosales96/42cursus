/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:50:34 by drosales          #+#    #+#             */
/*   Updated: 2024/07/24 10:21:03 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int size_stack(t_stack *stack)
{
    int i;

    i = 0;
    if(stack == NULL || stack->next == NULL)
        return;
    while (stack->next != NULL)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

t_stack *get_final_element(t_stack *stack)
{
    if (stack == NULL || stack->next == NULL)
        return;
    while (stack->next != NULL)
    {
        stack = stack->next;
    }
    return (stack);
}

t_stack *get_previous_last_element(t_stack *stack)
{
    if (stack == NULL || stack->next == NULL)
        return;
    t_stack *current;

    current = stack;
    while (stack->next->next != NULL)
    {
        current = current->next;
    }
    return (current);
}