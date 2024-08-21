/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:51:48 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 08:53:36 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	checking_commands(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		write(1, "Error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	*next_line;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < ac)
		numbers(av[i++], &stack_a);
	ft_42lines(&stack_a);
	next_line = NULL;
	while (1)
	{
		if (!next_line)
			return (1);
		next_line = get_next_line(STDIN_FILENO);
		if (checking_commands(&stack_a, &stack_b, next_line) == 0)
			free_2_stacks(&stack_a, &stack_b);
		free(next_line);
	}
	final_msg(&stack_a, &stack_b);
	free_2_stacks(&stack_a, &stack_b);
	return (0);
}
