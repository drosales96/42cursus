/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:11:04 by drosales          #+#    #+#             */
/*   Updated: 2024/08/21 12:18:27 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../inc/push_swap.h"

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
int		checking_commands(t_stack **stack_a, t_stack **stack_b, char *command);

#endif