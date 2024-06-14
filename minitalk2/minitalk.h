/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:58:47 by drosales          #+#    #+#             */
/*   Updated: 2024/06/13 12:15:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*======= ALL INCLUDES I NEED =======*/

#ifndef MINITALK_H
# define MINITALK_H

/*======= LIBRARIES =======*/

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>


/*======= FOR OS PROBLEMS WITH SA STRUCT =======*/

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 200809L
# endif

/*======= MY OWN LIBRARIES =======*/

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

/*======= FOR CLIENT FINAL TRANSMISSION =======*/

//# define END_TRANSMISSION '\0'

/*======= MESSAGES FOR ERRORS =======*/

# define ERROR_1 "Error 0: Arguments missing"
# define ERROR_2 "Error 1: Too many Arguments"
# define ERROR_3 "Error 2: Could not generate the PID"
# define ERROR_4 "Error 3: Invalid PID"
# define ERROR_5 "Error 4: Delivery failed"
# define INFO_MSG "Info message 1"
# define SUCCES_MSG "Success message 1"

/*======= COLOR FOR MESSAGES =======*/

/*======= REGULAR COLORS =======*/

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define ORANGE "\033[1;31m"

/*======= BOLD COLORS =======*/

# define BDBLACK "\033[1;30m"
# define BDRED "\033[1;31m"
# define BDGREEN "\033[1;32m"
# define BDYELLOW "\033[1;33m"
# define BDBLUE "\033[1;34m"
# define BDMAGENTA "\033[1;35m"
# define BDCYAN "\033[1;36m"
# define BDWHITE "\033[1;37m"

/*======= UNDERLINE COLORS =======*/

# define ULRED "\033[4;31m"
# define ULGREEN "\033[4;32m"
# define ULYELLOW "\033[4;33m"
# define ULBLUE "\033[4;34m"
# define ULMAGENTA "\033[4;35m"
# define ULCYAN "\033[4;36m"
# define ULWHITE "\033[4;37m"

/* ======= LINES, FILLS, MISCELLANY =======*/

# define EQLIN "\u2550"
# define LSHADE "\u2591"
# define MSHADE "\u2592"
# define HSHADE "\u2593"
# define FBLOCK "\u2588"
# define EBLOCK "\u258d"
# define ARROWRG "\u2911"

/*======= VISUAL EXAMPLE =======*/

// EQLIN    ═══════════════════
// LSHADE   ░░░░░░░░░░░░░░░░░░░
// MSHADE   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// HSHADE   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
// FBLOCK   ███████████████████
// EBLOCK   ▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍
// ARROWRG  ⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑

/*======= FUNCTION TO RESOLVE PROBLEMS WITH USLEEP =======*/

#endif