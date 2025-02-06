/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:10:17 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 12:37:46 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/examft.h"

/**
 * 
 * Assignment name  : ft_sort_list
 * Expected files   : ft_sort_list.c
 * Allowed functions:
 * ---------------------------------------------------------------
 * 
 * Write the following functions:
 * 
 * t_list	*ft_sort_list(t_list* lst, int (*cmp)(int, int));
 * 
 * This function must sort the list given as a parameter, using the function
 * pointer cmp to select the order to apply, and returns a pointer to the
 * first element of the sorted list.
 * 
 * Duplications must remain.
 * 
 * Inputs will always be consistent.
 * 
 * You must use the type t_list described in the file list.h
 * that is provided to you. You must include that file
 * (#include "list.h"), but you must not turn it in. We will use our own
 * to compile your assignment.
 * 
 * Functions passed as cmp will always return a value different from
 * 0 if a and b are in the right order, 0 otherwise.
 * 
 * For example, the following function used as cmp will sort the list
 * in ascending order:
 * 
 * int ascending(int a, int b)
 * {
 * 	return (a <= b);
 * } 
 * 
 */

t_list_2	*ft_sort_list(t_list_2 *lst, int (*cmp)(int, int))
{
	int			swap;
	t_list_2	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
