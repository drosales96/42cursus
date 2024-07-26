/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:31:54 by drosales          #+#    #+#             */
/*   Updated: 2024/07/26 10:38:58 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_biggest(t_stack **stack)
{
    t_stack *current;
    int     res;

    if (!(*stack))
        return (0);

    current = (*stack);
    res = current->index;
    while (current != NULL)
    {
        if (current->index > res)
            res = current->index;
        current = current->next;
    }
    return (res);
}

void    sort_three(t_stack  **stack)
{
    int biggest;
    int first_p;
    int second_p;
    int third_p:

    biggest = find_biggest((*stack));
    first_p = (*stack)->index;
    second_p = (*stack)->next->index;
    third_p = (*stack)->next->next->index;
    
    if (check_sort((*stack)))
        return;
    if (biggest == first_p)
    {
        if (second_p > third_p)
            do_sa(stack);
    }
    else if (biggest == second_p)
    {
        do_ra(stack);
        if (first_p > third_p)
            do_sa(stack);
    }
    else if (biggest == third_p)
    {
        do_rra(stack);
        if (first_p > second_p)
            do_sa(stack);
    }
}