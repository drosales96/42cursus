/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:02:25 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 12:04:29 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void    ft_swap(t_stack **stack)
{
    t_stack     *tmp;
    
    if (!(*stack) || (*stack)->next == NULL)
        return;
    tmp = (*stack);
    (*stack) = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

void    sa(t_stack **stack_a, int move)
{
    ft_swap(stack_a);
    if (move == 1)
        write(1, "sa\n", 3);
}

void    sb(t_stack **stack_b, int move)
{
    ft_swap(stack_b);
    if (move == 1)
        write(1, "sb\n", 3);
}

void    ss(t_stack **stack_a, t_stack **stack_b, int move)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    if (move)
        write(1, "ss\n", 3);
}

