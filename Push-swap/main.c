/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:40:13 by drosales          #+#    #+#             */
/*   Updated: 2024/08/08 11:49:10 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

static void    push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
    if (stack_size == 2 && !ft_is_sorted(*stack_a))
        sa(stack_a);
    if (stack_size == 3 && ft_is_sorted(*stack_a))
        return;
    else if (stack_size == 3 && !ft_is_sorted(*stack_a))
        sort_three(stack_a);
    else if (stack_size > 3 && !ft_is_sorted(*stack_a))
        sorting(stack_a, stack_b);
}

void    numbers(char *av, t_stack **stack_a)
{
    char        **arguments;
    long int    nbr;
    int         i;

    arguments = ft_split(av, ' ');
    i = 0;
    while (arguments[i])
    {
        if (ft_correct_input(arguments[i]))
        {
            nbr = ft_atol(arguments[i]);
            if (nbr > INT_MAX || nbr < INT_MIN)
				errors(stack_a, NULL);
            add_new_stack(stack_a, new_stack(nbr));
        }
        else
            errors(NULL, NULL);
        free(arguments[i]);
        i++;
    }
    free(arguments);
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
    free_stacks(&stack_a);
    free_stacks(&stack_b);
    return (0);
}