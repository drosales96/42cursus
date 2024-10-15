/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:46:02 by marigome          #+#    #+#             */
/*   Updated: 2024/10/11 13:23:10 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Inicializamos la estructura */

void    init_signals(t_signal *signals)
{
    signals->sigint = 0;
    signals->sigquit = 0;
    signals->exit = 0;
    signals->pid = 0;
}

/* SEÑALES

    Códigos de salida normales: Cuando un proceso finaliza normalmente (por ejemplo, usando exit(0) o exit(1)), 
    el código de salida es simplemente el valor pasado a exit().

    Códigos de salida debido a señales: Cuando un proceso es terminado por una señal, 
    el código de salida se ajusta a 128 + el número de la señal.

¿Por qué 128?

En Unix/Linux, los códigos de salida para procesos tienen un rango de 0 a 255. 
Los números de 0 a 127 se reservan para los procesos que terminan de manera normal (con exit()), 
y los números de 128 a 255 se usan para indicar que un proceso fue terminado por una señal.

El número 128 actúa como un indicador de que el proceso fue terminado por una señal, no por una finalización normal. */

/* CONTROL + C -> SIGINT (Señal 2)*/

static void sig_int(int status)
{
    (void)status;
    
    if (g_signals.pid == 0)  // Si no hay proceso hijo //
    {
        ft_putstr_fd("\n", STDERR);
        ft_putstr_fd("minishell:~$ ", STDERR);
        g_signals.exit = 1;
    }
    else
    {
        ft_putstr_fd("\n", STDERR);
        g_signals.exit = 130;  // Salida común para SIGINT
    }
    g_signals.sigint = 1;  // Señalizamos que hemos recibido la señal
}

/* CONTROL + \ -> SIGQUIT (Señal 3)*/

static void sig_quit(int status)
{
    (void)status;

    if (g_signals.pid != 0)
    {
        ft_putstr_fd("Quit: 3\n", STDERR);
        g_signals.exit = 131;  // Salida común para SIGQUIT
    }
}

void    sig_init(void)
{
    signal(SIGINT, &sig_int);
    signal(SIGQUIT, &sig_quit);
}


