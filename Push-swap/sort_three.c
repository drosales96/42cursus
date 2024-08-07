/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:31:54 by drosales          #+#    #+#             */
/*   Updated: 2024/08/07 12:24:51 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_biggest(t_stack *stack)
{
    t_stack *current;
    int     res;

    if (!stack)
        return (0);
    current = stack;
    res = current->index;
    while (current != NULL)
    {
        if (current->index > res)
            res = current->index;
        current = current->next;
    }
    return (res);
}

void	sort_three(t_stack **stack)
{
	int	biggest;

	if (ft_is_sorted(*stack))
		return ;
	biggest = find_biggest(*stack);
	if ((*stack)->index == biggest)
		ra(stack);
	else if ((*stack)->next->index == biggest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}