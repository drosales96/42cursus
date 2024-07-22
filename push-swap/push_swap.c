/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:46:06 by drosales          #+#    #+#             */
/*   Updated: 2024/07/22 11:52:32 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;

    if (ac == 1 || ac == 2 && !av[1][0])
        return (EXIT_FAILURE);
    else if (ac == 2)
        av = ft_split(av[1], ' ');
    init_stack_a(&a, av + 1);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, EXIT_FAILURE);
        else if(stack_len(a) == 3)
            sort_three(&a);
        else
            sort_stacks(&a, &b);
    }
    free_stack(&a);
    return (0);
}