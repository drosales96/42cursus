/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:49:59 by drosales          #+#    #+#             */
/*   Updated: 2024/08/06 07:17:39 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int     size_a;
    int     size_b;

    tmp_a = (*stack_a);
    tmp_b = (*stack_b);
    size_a = size_stack(tmp_a);
    size_b = size_stack(tmp_b);
    while (tmp_b)
    {
        tmp_b->cost_b = tmp_b->pos;
        if (tmp_b->pos > size_b / 2)
            tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
        tmp_b->cost_a = tmp_b->target;
        if (tmp_b->target > size_a / 2)
            tmp_b->cost_a = (size_a - tmp_b->target) * -1;
        tmp_b = tmp_b->next;
    }
}

void    cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int     cheapest;
    int     cost_a;
    int     cost_b;

    tmp = *stack_b;
    cheapest = INT_MAX;
    while (tmp)
    {
        if(neg_to_pos(tmp->cost_a) + neg_to_pos(tmp->cost_b) < cheapest)
        {
            cheapest = neg_to_pos(tmp->cost_a) + neg_to_pos(tmp->cost_b);
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
        }
        tmp = tmp->next;
    }
    ft_moves(stack_a, stack_b, cost_a, cost_b);
}

