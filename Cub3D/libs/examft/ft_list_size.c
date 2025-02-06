/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:05:30 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:36:06 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_list_size
 * Expected files   : ft_list_size.c, ft_list.h
 * Allowed functions:
 * -----------------------------------------------------------
 * 
 * Write a function that returns the number of elements in the linked 
 * list that's passed to it.
 * 
 * It must be declared as follows:
 * 
 * int	ft_list_size(t_list *begin_list);
 * 
 * You must use the following structure, and turn it in as a file called
 * ft_list.h: (allocated in examft.h)
 * 
 * typedef struct    s_list
 * {
 *     struct s_list *next;
 *     void          *data;
 * }                 t_list;
 *  
 */

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	if (begin_list == NULL)
		return (0);
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
