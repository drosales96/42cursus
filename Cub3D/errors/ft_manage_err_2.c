/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:30:57 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/04 21:10:32 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_manage_err_rgb" logs an error message specifically for 
 * invalid RGB values found in the map file. It provides details about the 
 * type of error, the invalid character, and its position (row and column) in 
 * the map data.
 * 
 * @param const char *err       A pointer to a string describing the type 
 *                              of error (e.g., "Invalid RGB format").
 * @param char **cell           A 2D array of strings representing the map or
 *                              RGB data being analyzed.
 * @param int row               The row index of the invalid character.
 * @param int col               The column index of the invalid character.
 * 
 * @return void                 This function does not return a value. It 
 *                              prints the error details to the console.
 * 
 * The function "ft_manage_err_id" logs an error message related to an 
 * invalid or problematic identifier. It formats the error message using 
 * styles and macros for clarity and consistency.
 * 
 * @param const char *id				A pointer to the identifier string 
 * 										that caused the error.
 * 
 * @return void 
 * 
 */

void	ft_manage_err_rgb(const char *err, char **cell, int row, int col)
{
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW "%s\n", err);
	ft_printf(RED "%c" RESET YELLOW LINE2_ERR RESET RED "%i.\n\n" RESET, \
	cell[row][col], row);
}

void	ft_manage_err_id(const char *id)
{
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW IDENT_ERR RESET RED "%s" RESET YELLOW IDENT2_ERR RESET "\n\n", id);
}
