/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_banner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:55:57 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/27 21:39:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_print_banner" generates the project start banner. 
 * 
 */

void	ft_print_banner(void)
{
	printf(RED"   ____      _     ____     _ \n"RESET);
	printf(RED"  / ___|   _| |__ |___ \\ __| |\n"RESET);
	printf(YELLOW" | |  | | | | '_ \\  __)|/ _` |\n"RESET);
	printf(YELLOW" | |__| |_| | |_) |__ )| (_| |\n"RESET);
	printf(RED"  \\____\\__,_|_.__/|____/\\__,_|\n"RESET);
	printf("\n"RESET);
	printf(RED"  Welcome to "BDBLUE"Cub3d, "RED"project by " GREEN \
	"drosales " RED "and " GREEN "rdel-olm\n");
	printf("\n");
}
