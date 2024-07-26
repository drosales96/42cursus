/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:29:18 by drosales          #+#    #+#             */
/*   Updated: 2024/07/26 10:03:52 by drosales         ###   ########.fr       */
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
# include <limits.h>

/*ESTRUCTURA LISTA ENLAZADA SENCILLA*/

typedef struct s_stack
{
  int                 index;
  int                 value;
  int                 pos;
  int                 target;
  int                 cost_a;
  int                 cost_b;
  struct s_stack      *next;
}                     t_stack;

/*MOVE FUNCTIONS*/

/*SWAP*/

void    ft_swap(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);

/*PUSH*/

void    ft_push(t_stack **dst, t_stack **src);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);

/*ROTATE*/

void    ft_rotate(t_stack **stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);

/*REVERSE ROTATE*/

void    ft_rrotate(t_stack **stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack  **stack_b);

/*UTILS FUNCTIONS*/

int     size_stack(t_stack *stack);
t_stack *get_final_element(t_stack *stack);
t_stack *get_previous_last_element(t_stack *stack);
int     check_sort(t_stack **stack);
int     find_biggest(t_stack **stack);

#endif