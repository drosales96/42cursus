/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_tratement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:52:30 by drosales          #+#    #+#             */
/*   Updated: 2024/08/06 09:26:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_correct_input(char *str)
{
    int i;

    i = 0;

    if ((str[i] == '-' || ((str[i] == '+') && (ft_strlen(str) > 1))))
        i++;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_duplicate(t_stack *stack) 
{
    t_stack *first;
    t_stack *second;

    first = stack;
    while (first)
    {
        second = first->next;
        while (second)
        {
            if (first->value == second->value)
                return (1);
            second = second->next;
        }
        first = first->next;
    }
    return (0);
}