/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:12:39 by drosales          #+#    #+#             */
/*   Updated: 2024/07/24 09:17:06 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_push(t_stack **dst, t_stack **src)
{
    t_stack *tmp;

    if (*src == NULL)
        return;
    tmp = (*src)->next;
    (*src)->next = (*dst);
    *dst = *src;
    *src = tmp;
}

static void    pa(t_stack **stack_a, t_stack **stack_b)
{
    ft_push(*stack_a, *stack_b);
    write(1, "pa\n", 3);
}

static void    pb(t_stack **stack_a, t_stack **stack_b)
{
    ft_push(*stack_b, *stack_a);
    write(1, "pb\n", 3);
}