/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:02:25 by drosales          #+#    #+#             */
/*   Updated: 2024/08/06 09:08:33 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    sa(t_stack **stack_a)
{
    ft_swap(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **stack_b)
{
    ft_swap(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    write(1, "ss\n", 3);
}

