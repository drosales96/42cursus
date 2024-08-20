/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_tratement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:52:30 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 09:17:36 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long int    ft_correct_input(char *str)
{
    int i;

    i = 0;
    if ((str[i] == '-' || str[i] == '+') && (ft_strlen(str) > 1))
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
    t_stack *current;
    t_stack *next_nb;
    
    current = stack;
    while (current)
    {
        next_nb = current->next;
        while (next_nb)
        {
            if (current->value == next_nb->value)
                return (1);
            next_nb = next_nb->next;
        }
        current = current->next;
    }
    return (0);
}

long int    ft_atol(const char *str)
{
    int             i;
    long int        res;
    int             sign;

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