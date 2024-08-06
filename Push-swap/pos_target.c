/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:43:39 by drosales          #+#    #+#             */
/*   Updated: 2024/08/06 09:15:09 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void get_position(t_stack **stack)
{
    int     i;
    t_stack *tmp;

    i = 0;
    tmp = (*stack);
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

static int   get_target(t_stack **stack_a, int index_b, int target_i, int target)
{
    t_stack *tmp;

    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->index > index_b && tmp->index < target_i)
        {
            target_i = tmp->index;
            target = tmp->pos;
        }
        tmp = tmp->next;
    }
    if (target != INT_MAX)
        return (target);
    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->index < target_i)
        {
            target_i = tmp->index;
            target = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (target);
}

int lowest_position_index(t_stack **stack)
{
    t_stack *tmp;
    int     lowest_i;
    int     lowest_pos;

    tmp = *stack;
    lowest_i = INT_MAX;
    get_position(stack);
    lowest_pos = tmp->pos;
    while (tmp)
    {
        if (tmp->index < lowest_i)
        {
            lowest_i = tmp->index;
            lowest_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (lowest_pos);
}

void    get_target_position(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int     target;

    tmp = *stack_b;
    get_position(stack_a);
    get_position(stack_b);
    target = 0;
    while (tmp)
    {
        target = get_target(stack_a, tmp->index, INT_MAX, target);
        tmp->target = target;
        tmp = tmp->next;
    }
}

void ft_get_index(t_stack *stack_a, int stack_len_max)
{
    t_stack *ptr;
    t_stack *bigger;
    int     value;

    while (--stack_len_max > 0)
    {
        ptr = stack_a;
        bigger = NULL;
        value = INT_MIN;
        while (ptr)
        {
            if (ptr->value == value && ptr->index == 0)
                ptr->index = 1;
            if (ptr->value > value && ptr->index == 0)
            {
                value = ptr->index;
                bigger = ptr;
                ptr = ptr->next;
            }
            else
                ptr = ptr->next;
        }
        if (bigger != NULL)
            bigger->index = stack_len_max;
    }
}