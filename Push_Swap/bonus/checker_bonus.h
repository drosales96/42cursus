/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:11:04 by drosales          #+#    #+#             */
/*   Updated: 2024/08/20 17:45:24 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define BUFFER_SIZE 42

char    *get_next_line(int fd);
int     checking_commands(t_stack **stack_a, t_stack **stack_b, char *command);

#endif