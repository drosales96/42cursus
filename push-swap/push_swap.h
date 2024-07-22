/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:29:18 by drosales          #+#    #+#             */
/*   Updated: 2024/07/22 09:44:15 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

/*INCLUDES FOR MY OWN LIBRARIES*/

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

/*C LIBRARIES*/

# include <stdlib.h>
# include <unistd.h>

typedef struct stack_node
{
    int                 num;
    int                 index;
    int                 push_cost;
    struct stack_node   *target_node;
    struct stack_node   *next;
    struct stack_node   *prev;
}   t_stack_node;


#endif