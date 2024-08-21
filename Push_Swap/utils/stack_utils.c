/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:50:34 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 09:24:39 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->pos = -1;
	new_stack->target = -1;
	new_stack->cost_a = -1;
	new_stack->cost_b = -1;
	new_stack->next = NULL;
	return (new_stack);
}

void	add_new_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_element;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last_element = get_final_element(*stack);
	last_element->next = new_node;
}

int	size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*get_final_element(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*get_previous_last_element(t_stack *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
