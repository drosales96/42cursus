/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:17 by drosales          #+#    #+#             */
/*   Updated: 2024/08/07 08:02:13 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        rr(a, b);
    }
}

static  void reverse_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        rrr(a, b);
    }
}

static  void rotate_a(t_stack **a, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            ra(a);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rra(a);
            (*cost)++;
        }
    }
}

static void rotate_b(t_stack **b, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            rb(b);
            (*cost)--;
        }    
        else if (*cost < 0)
        {
            rrb(b);
            (*cost)++;
        }
    }
}

void ft_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        reverse_ab(a, b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        rotate_ab(a, b, &cost_a, &cost_b);
    rotate_a(a, &cost_a);
    rotate_b(b, &cost_b);
    pa(a, b);
}