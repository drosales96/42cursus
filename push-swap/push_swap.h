/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:29:18 by drosales          #+#    #+#             */
/*   Updated: 2024/07/23 11:10:41 by drosales         ###   ########.fr       */
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

typedef struct s_list
{
  int               nb;
  int               index;
  int               value;
  struct s_list     *stack;
  struct s_list     *next;
  struct s_list     *prev;
}t_list;


#endif