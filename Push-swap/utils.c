/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:38:31 by drosales          #+#    #+#             */
/*   Updated: 2024/08/06 07:49:43 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stacks(t_stack **stack)
{
    if (!stack || !(*stack))
        return;
    t_stack *tmp;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

void errors(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !(*stack_a))
        free_stacks(stack_a);
    if (!stack_b || !(*stack_b))
        free_stacks(stack_b);
    write(2, "ERROR\n", 6);
    exit(1);
}

long int    ft_atol(char *str)
{
    long int i;
    long int res;
    long int sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && ft_isdigit(str[i]))
    {
        res = (res * 10) + str[i] - 48;
        i++;
    }
    return (res * sign);
}