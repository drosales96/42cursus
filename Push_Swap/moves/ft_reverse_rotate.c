/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:58:26 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 19:04:43 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*static void ft_rrotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *prev_tail;

    tail = get_final_element(*stack);
    prev_tail = get_previous_last_element(*stack);
    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    prev_tail->next = NULL;
}*/

static void ft_rrotate(t_stack **stack)
{
    t_stack *tail;
    t_stack *prev_tail;
    t_stack *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return; 
    tail = get_final_element(*stack);
    prev_tail = get_previous_last_element(*stack);
    if (tail == NULL || prev_tail == NULL)
        return; 
    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    prev_tail->next = NULL;
}


void    rra(t_stack **stack_a, int move)
{
    ft_rrotate(stack_a);
    if (move == 1)
        write(1, "rra\n", 4);
}

void    rrb(t_stack **stack_b, int move)
{
    ft_rrotate(stack_b);
    if (move == 1)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack **stack_a, t_stack  **stack_b, int move)
{
    ft_rrotate(stack_a);
    ft_rrotate(stack_b);
    if (move == 1)
        write(1, "rrr\n", 4);
}
