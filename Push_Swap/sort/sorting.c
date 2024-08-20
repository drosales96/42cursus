/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:56:54 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 11:54:29 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void nb_partition(t_stack **stack_a, t_stack **stack_b)
{
    int pushes;
    int stack_size;
    int i;

    stack_size = size_stack(*stack_a);
    pushes = 0;
    i = 0;
    while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
    {
        if ((*stack_a)->index <= stack_size / 2)
        {
            pb(stack_a, stack_b, 1);
            pushes++;
        }
        else
            ra(stack_a, 1);
        i++;
    }
    while (stack_size - pushes > 3)
    {
        pb(stack_a, stack_b, 1);
        pushes++;
    }
}

static void sorting_stack(t_stack **stack_a)
{
    int lower_pos;
    int stack_size;

    stack_size = size_stack(*stack_a);
    lower_pos = lowest_position_index(stack_a);
    if (lower_pos > stack_size / 2)
    {
        while (lower_pos < stack_size)
        {
            rra(stack_a, 1);
            lower_pos++;
        }
    }
    else
    {
        while (lower_pos > 0)
        {
            ra(stack_a, 1);
            lower_pos--;
        }
    }
}

void    sorting(t_stack **stack_a, t_stack **stack_b)
{
    nb_partition(stack_a, stack_b);
    sort_three(stack_a);
    while (*stack_b)
    {
        get_target_position(stack_a, stack_b);
        move_cost(stack_a, stack_b);
        cheapest_move(stack_a, stack_b);
    }
    if (!ft_is_sorted(*stack_a))
        sorting_stack(stack_a);
}