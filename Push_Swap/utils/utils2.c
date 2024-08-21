/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:53:31 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 09:26:52 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	numbers(char *av, t_stack **stack_a)
{
	char		**arguments;
	long int	nbr;
	int			i;

	arguments = ft_split(av, ' ');
	i = 0;
	while (arguments[i])
	{
		if (ft_correct_input(arguments[i]))
		{
			nbr = ft_atol(arguments[i]);
			if (nbr > INT_MAX || nbr < INT_MIN)
			{
				errors(stack_a, NULL);
			}
			add_new_stack(stack_a, new_stack(nbr));
		}
		else
			errors(NULL, NULL);
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	free_2_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stacks(stack_a);
	free_stacks(stack_b);
}

int	ft_42lines(t_stack **stack_a)
{
	if (ft_duplicate(*stack_a))
		errors(stack_a, NULL);
	else
		size_stack(*stack_a);
	return (0);
}

void	final_msg(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_a) && (stack_b == NULL) && ft_is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
