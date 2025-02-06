/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:21:03 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/03 13:54:58 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_players" validates the number of players in the map. It 
 * ensures that there is exactly one player ('N', 'S', 'E', or 'W') in the map 
 * and prints appropriate error messages if this condition is violated.
 * 
 * @param int index					The number of players detected in the map.
 * 									Expected to be exactly 1 for a valid map.
 * 
 * @return void
 * 
 * The function "ft_forbidden_space" logs an error message when a forbidden 
 * space is detected at a specific position in the map. It prints the line 
 * and column number of the invalid space to help with debugging.
 * 
 * @param int line					The line index in the map where the 
 * 									forbidden space was found (0-based index).
 * @param int col					The column index in the map where the 
 * 									forbidden space was found (0-based index).
 * 
 * @return void
 * 
 * The function "ft_invalid_side" logs an error message when an issue is 
 * detected with the left or right side of a map line. It provides a detailed 
 * description of the error, specifying the side (left or right) and the line 
 * number where the problem occurred.
 * 
 * @param int line					The line index in the map where the error 
 * 									was detected.
 * @param int warning				A flag indicating the type of error:
 * 										1 for an issue on the left side.
 * 										2 for an issue on the right side.
 * 
 * @return void
 * 
 * The function "ft_invalid_char" logs detailed information about an invalid 
 * character detected in the map. It specifies the invalid character, its 
 * line number, and its position within the line, helping with debugging.
 * 
 * @param char **map				A 2D array representing the map being 
 * 									verified.
 * @param int line					The line index in the map where the 
 * 									invalid character was found.
 * @param int pos					The column index in the line where the 
 * 									invalid character was found.
 *
 * @return void
 * 
 * The function "ft_manage_err" handles the detection of errors by printing 
 * an error message to the screen. The error message is passed as an argument, 
 * typically defined in a header file (e.g., `macros.h`), and formatted for 
 * readability.
 * 
 * @param const char *err			A pointer to the error message string, 
 * 									passed as a macro.
 * 
 * @return void
 * 
 */

void	ft_manage_err(const char *err)
{
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW "%s\n\n" RESET, err);
}

void	ft_invalid_char(char **map, int line, int pos)
{
	char	letter;

	letter = map[line][pos];
	ft_printf(BDRED "Error: \n" RESET RED INIT_ERR RESET GREEN ARROW RESET \
	YELLOW CHAR1_ERR "\"" RESET BLUE "%c" RESET YELLOW "\" ...\n" RESET, \
	letter);
	ft_printf(YELLOW CHAR2_ERR RESET RED "%i" RESET YELLOW CHAR3_ERR RESET \
	RED "%i" RESET YELLOW "." RESET "\n\n", line + 1, pos + 1);
}

void	ft_invalid_side(int line, int warning)
{
	if (warning == 1)
	{
		ft_printf(BDRED "Error: \n" RESET RED SIDE_LEFT_ERR "\n" RESET);
		ft_printf(YELLOW LINE_ERR RESET GREEN "%i.\n\n" RESET, line + 1);
	}
	if (warning == 2)
	{
		ft_printf(BDRED "Error: \n" RESET RED SIDE_RIGHT_ERR "\n" RESET);
		ft_printf(YELLOW LINE_ERR RESET GREEN "%i.\n\n" RESET, line + 1);
	}
}

void	ft_forbidden_space(int line, int col)
{
	ft_printf(BDRED "Error: \n" RESET);
	ft_printf(RED FORB_SPC_ERR RESET YELLOW FORB_SPC2_ERR RESET GREEN "%i" \
	RESET YELLOW CHAR3_ERR RESET GREEN "%i.\n\n", line + 1, col + 1);
}

void	ft_players(int index)
{
	if (index == 0)
		ft_printf(BDRED "Error: \n" RESET YELLOW PLAYERS_0_ERR RESET "\n\n");
	if (index > 1)
		ft_printf(BDRED "Error: \n" RESET YELLOW PLAYERS_NO1_ERR RESET "\n\n");
}
