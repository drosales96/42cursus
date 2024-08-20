/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:40:13 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 11:52:26 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void    push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
    if (stack_size == 2 && !ft_is_sorted(*stack_a))
        sa(stack_a, 1);
    if (stack_size == 3 && ft_is_sorted(*stack_a))
        return;
    else if (stack_size == 3 && !ft_is_sorted(*stack_a))
        sort_three(stack_a);
    else if (stack_size > 3 && !ft_is_sorted(*stack_a))
        sorting(stack_a, stack_b);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     stack_size;
    int     i;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    while (i < ac)
    {
        numbers(av[i], &stack_a);
        i++;
    }
    if (ft_duplicate(stack_a))
        errors(&stack_a, NULL);
    stack_size = size_stack(stack_a);
    ft_get_index(stack_a, stack_size + 1);
    push_swap(&stack_a, &stack_b, stack_size);
    free_2_stacks(&stack_a, &stack_b);
    return (0);
}