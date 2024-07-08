/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:58:15 by drosales          #+#    #+#             */
/*   Updated: 2024/07/08 09:58:28 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp;

	i = 8;
	temp = character;
	while (i > 0)
	{
		i--;
		temp = character >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
	}
}

int	main(int ac, char *av[])
{
	int			pid;
	const char	*message;
	int			i;

	if (ac != 3)
	{
		ft_printf(RED ERROR_1, av[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	i = 0;
	while (message[i])
		send_signal(pid, message[i++]);
	send_signal(pid, '\0');
	return (0);
}
