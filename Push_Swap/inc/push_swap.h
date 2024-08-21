/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:29:18 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 11:26:15 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*C LIBRARIES*/
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

/*INCLUDES FOR MY OWN LIBRARIES*/

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				index;
	int				value;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/*MOVE FUNCTIONS*/

/*SWAP*/

void		sa(t_stack **stack_a, int move);
void		sb(t_stack **stack_b, int move);
void		ss(t_stack **stack_a, t_stack **stack_b, int move);

/*PUSH*/

void		pa(t_stack **stack_a, t_stack **stack_b, int move);
void		pb(t_stack **stack_a, t_stack **stack_b, int move);

/*ROTATE*/

void		ra(t_stack **stack_a, int move);
void		rb(t_stack **stack_b, int move);
void		rr(t_stack **stack_a, t_stack **stack_b, int move);

/*REVERSE ROTATE*/

void		rra(t_stack **stack_a, int move);
void		rrb(t_stack **stack_b, int move);
void		rrr(t_stack **stack_a, t_stack **stack_b, int move);

/*UTILS FUNCTIONS*/

int			size_stack(t_stack *stack);
t_stack		*get_final_element(t_stack *stack);
t_stack		*get_previous_last_element(t_stack *stack);
int			ft_is_sorted(t_stack *stack);
int			ft_duplicate(t_stack *stack);
void		ft_get_index(t_stack *stack_a, int stack_len_max);
long int	ft_correct_input(char *str);
int			neg_to_pos(int nb);
void		ft_moves(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		add_new_stack(t_stack **stack, t_stack *new_node);
t_stack		*new_stack(int value);
long int	ft_atol(const char *str);
void		errors(t_stack **stack_a, t_stack **stack_b);
void		free_stacks(t_stack **stack);
void		free_2_stacks(t_stack **stack_a, t_stack **stack_b);
void		numbers(char *av, t_stack **stack_a);

/*CHECKER EXTRA FUNCTIONS*/

int			ft_42lines(t_stack **stack_a);

/*FOR COSTS*/

void		move_cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);

/*TO FIND POSITION OR TARGET*/

int			lowest_position_index(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/*SORTS*/

void		sort_three(t_stack **stack);
void		sorting(t_stack **stack_a, t_stack **stack_b);

#endif