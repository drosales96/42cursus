/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:30:07 by drosales          #+#    #+#             */
/*   Updated: 2024/06/14 12:30:22 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void    send_signal(int pid, unsigned char character)
{
    int             i;
    unsigned char   temp;

    i = 8;
    temp = character;
    while (i > 0)
    {
        i--;
        temp = character >> i;
        if (temp % 2 == 0)
        {
            kill(pid, SIGUSR2);
        }
        else
        {
            kill(pid, SIGUSR1);
        }
       usleep(150);
    }
}

static void handle_sneak(int signal)
{
    if (signal == SIGUSR1)
        ft_printf(GREEN"Bit 1 recieved\n");
    else if (signal == SIGUSR2)
        ft_printf(GREEN"Bit 0 recieved\n");
}

int main(int ac, char *av[])
{
    pid_t       PID;
    const char  *message;
    int         i;
    
    signal(SIGUSR1, handle_sneak);
    signal(SIGUSR2, handle_sneak);
    if (ac != 3)
    {
        ft_printf(RED ERROR_1, av[0]);
        exit(EXIT_FAILURE);
    }
    PID = ft_atoi(av[1]);
    message = av[2];
    i = 0;
    while (message[i])
        send_signal(PID, message[i++]);
    send_signal(PID, '\0');
    return (0);
}