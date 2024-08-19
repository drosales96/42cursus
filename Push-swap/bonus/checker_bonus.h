/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:11:04 by drosales          #+#    #+#             */
/*   Updated: 2024/08/19 18:37:50 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define BUFFER_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char *get_next_line(int fd);

#endif