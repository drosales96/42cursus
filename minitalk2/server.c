/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:59:45 by drosales          #+#    #+#             */
/*   Updated: 2024/06/13 12:19:13 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handle_sig(int signal)
{
    static unsigned char    bits;
    static int              bit_counter;

    bits <<= 1;
    if (signal == SIGUSR1)
        bits |= 1;
    bit_counter++;
    if (bit_counter == 8)
    {
        if ((int)bits <= 126)
            ft_printf("%c", bits);
        else if ((int)bits >= 127)
            ft_printf(RED "%c", bits);
        bit_counter = 0;
        bits = '\0';
    }
}

static void ft_signals(void)
{
    struct sigaction    sa;    
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handle_sig;
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        exit(EXIT_FAILURE);
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        exit(EXIT_FAILURE);
}
static void ft_getcheckpid(void)
{
    int pid;    
    
    pid = getpid();
    if (!pid)
        ft_printf(BDRED ERROR_4 "\n");
    ft_printf(CYAN"\nWelcome to drosales's Minitalk proyect\n\n");
    ft_printf(GREEN"Server is prepare to work!\n\n");
    ft_printf(""CYAN"The PID of this server is: "WHITE"%d\n\n", pid);
}
void ft_title()
{
    ft_printf(RED"  __  __ _       _ _        _    \n");
    ft_printf(RED" |  \\/  (_)     (_) |      | |   \n");
    ft_printf(RED" | \\  / |_ _ __  _| |_ __ _| | __\n");
    ft_printf(RED" | |\\/| | | '_ \\| | __/ _` | |/ /\n");
    ft_printf(RED" | |  | | | | | | | || (_| |   < \n");
    ft_printf(RED" |_|  |_|_|_| |_|_|\\__\\__,_|_|\\_\\\n\n");
}

int main(void)
{
    ft_title();
    ft_getcheckpid();
    ft_signals();
    while (1)
        sleep(300);
    return (0);
}