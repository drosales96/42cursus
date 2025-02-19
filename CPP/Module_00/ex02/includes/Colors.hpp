/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:25:26 by drosales          #+#    #+#             */
/*   Updated: 2025/02/19 12:25:29 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

// =======================================================
// # Regular Colors ANSI
// =======================================================

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define BLUE		"\033[0;34m"
# define WHITE		"\033[0;37m"
# define BLACK      "\033[0;30m"

// =======================================================
// # Other Colors ANSI
// =======================================================

# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define ORANGE 	"\033[1;31m"
# define RESET      "\033[0;0m"

// =======================================================
// # Bold ANSI
// =======================================================

# define BDBLACK 	"\033[1;30m"
# define BDRED 		"\033[1;31m"
# define BDGREEN 	"\033[1;32m"
# define BDYELLOW 	"\033[1;33m"
# define BDBLUE 	"\033[1;34m"
# define BDMAGENTA 	"\033[1;35m"
# define BDCYAN 	"\033[1;36m"
# define BDWHITE 	"\033[1;37m"

// =======================================================
// # Underline ANSI
// =======================================================

# define ULRED 		"\033[4;31m"
# define ULGREEN 	"\033[4;32m"
# define ULYELLOW 	"\033[4;33m"
# define ULBLUE 	"\033[4;34m"
# define ULMAGENTA 	"\033[4;35m"
# define ULCYAN 	"\033[4;36m"
# define ULWHITE 	"\033[4;37m"

// =======================================================
// # Lines, fills, miscellany
// # (see graphics bellow)
// =======================================================

# define EQLIN 		"\u2550"
# define LSHADE 	"\u2591"
# define MSHADE 	"\u2592"
# define HSHADE 	"\u2593"
# define FBLOCK 	"\u2588"
# define EBLOCK 	"\u258d"
# define ARROWRG 	"\u2911"

// =======================================================
// # Regular Colors HEXadecimal
// =======================================================

# define REDHEX		"0xff0000"
# define GREENHEX	"0x00ff00"
# define BLUEHEX	"0x0000ff"
# define WHITEHEX	"0xffffff"
# define BLACKHEX 	"0x000000"

// =======================================================
// # Others Colors HEXadecimal
// =======================================================

# define YELLOWHEX	"0xffff00"
# define MAGENTAHEX	"0xff00ff"
# define CYANHEX	"0x00ffff"
# define ORANGEHEX 	"0xffa500"
# define GREYHEX 	"0x808080"
# define NAVYHEX 	"0x000080"
# define OLIVEHEX 	"0x808000"
# define SILVERHEX 	"0xc0c0c0"

#endif

// EQLIN	═══════════════════
// LSHADE	░░░░░░░░░░░░░░░░░░░
// MSHADE	▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// HSHADE	▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
// FBLOCK	███████████████████
// EBLOCK	▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍
// ARROWRG	⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑