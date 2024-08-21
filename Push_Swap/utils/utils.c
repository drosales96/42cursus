/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:38:31 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 09:26:02 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	errors(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_a != NULL)
		free_stacks(stack_a);
	if (stack_b == NULL || stack_b != NULL)
		free_stacks(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	neg_to_pos(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_get_index(t_stack *stack_a, int stack_len_max)
{
	t_stack	*ptr;
	t_stack	*bigger;
	int		value;

	while (--stack_len_max > 0)
	{
		ptr = stack_a;
		bigger = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
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
