/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:58:15 by drosales          #+#    #+#             */
/*   Updated: 2024/06/13 12:09:32 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    send_signal(const int pid, char character)
{
    int             i;
    
    i = 7;
    while (i >= 0)
    {
        if (((character >> i) & 1) == 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i--;
        usleep(100);
    }
}

int main(int ac, char *av[])
{
    int       pid;
    int         i;

    if (ac <= 2)
    {
        ft_printf("\n");
        exit(EXIT_FAILURE);
    }
    pid = ft_atoi(av[1]);
    if (ac == 3)
    {
        i = 0;
        while (av[2][i])
            send_signal(pid, av[2][i++]);
        send_signal(pid, '\0');
    }
    return (0);
}