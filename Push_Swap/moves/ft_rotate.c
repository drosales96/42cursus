/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:09:45 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 12:08:47 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void ft_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    tmp = *stack;
    *stack = (*stack)->next;
    tail = get_final_element(*stack);
    tmp->next = NULL;
    tail->next = tmp;
}

void ra(t_stack **stack_a, int move)
{
    ft_rotate(stack_a);
    if (move == 1)
        write(1, "ra\n", 3);
}

void rb(t_stack **stack_b, int move)
{
    ft_rotate(stack_b);
    if (move == 1)
        write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b, int move)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    if (move == 1)
        write(1, "rr\n", 3);
}

