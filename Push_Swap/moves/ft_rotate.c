/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:09:45 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 09:19:55 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = get_final_element(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **stack_a, int move)
{
	ft_rotate(stack_a);
	if (move == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int move)
{
	ft_rotate(stack_b);
	if (move == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int move)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (move == 1)
		write(1, "rr\n", 3);
}
