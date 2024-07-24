/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:31:54 by drosales          #+#    #+#             */
/*   Updated: 2024/07/24 08:12:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int case_checker(t_stack *stack)
{
    if ((stack->nb < stack->next->nb) && (stack->next->nb < stack->prev->nb))/*1 < 2 < 3*/
        return (1);
    else if ((stack->nb > stack->next->nb) && (stack->next->nb < stack->prev->nb) && (stack->prev->nb > stack->nb))/*3 > 1 > 2*/
        return (2);
    else if ((stack->nb > stack->next->nb) && (stack->next->nb > stack->prev->nb) && (stack->prev->nb < stack->nb))/*3 > 2 > 1*/
        return (3);
    else if ((stack->nb > stack->next->nb) && (stack->next->nb < stack->prev->nb) && (stack->prev->nb < stack->nb)) /*2 < 1 < 3*/
        return (4);
    else if ((stack->nb < stack->next->nb) && (stack->next->nb > stack->prev->nb) && (stack->prev->nb > stack->nb))/*1 < 3 < 2*/
        return (5);
    else
        return (6);/*2 < 3 < 1*/
}

/*TABLA CASUÍSTICA

1 2 3
1 3 2
2 3 1
2 1 3
3 2 1
3 1 2

NUM = 3

CASUÍSTICA = 3 x 2 x 1 = 6

*/

void    sort_three(t_stack **stack)
{
    int cases = case_checker(*stack);

    if (size_stack(*stack) == 1 || size_stack(*stack) == 1)
        ft_printf("ERROR");
    else if (cases == 1)
        return;
    else if (cases == 2)
        sa(stack, 1);
    else if (cases == 3)
        X
    else if (cases == 4)
        X
    else if (cases == 5)
        X
    else
        X //case 6
    
}