/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:46:02 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 17:43:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sig_int(int status)
{
	(void)status;
	if (g_signals.pid == 0)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_putstr_fd("drosales@marigome_shell:~$ ", STDERR_FILENO);
		g_signals.exit = 1;
	}
	else
	{
		ft_putstr_fd("\n", STDERR);
		g_signals.exit = 130;
	}
	g_signals.sigint = 1;
}

static void	sig_quit(int status)
{
	(void)status;
	if (g_signals.pid != 0)
	{
		ft_putstr_fd("Quit: 3\n", STDERR);
		kill(g_signals.pid, SIGQUIT);
	}
}

void	sig_chld_handler(int signum)
{
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, WNOHANG);
	(void)signum;
	while (pid > 0)
	{
		if (WIFEXITED(status))
		{
			g_signals.exit = WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			g_signals.exit = 128 + WTERMSIG(status);
		}
	}
}

void	sig_init(void)
{
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	signal(SIGCHLD, &sig_chld_handler);
}

void	init_signals(t_signal *signals)
{
	signals->sigint = 0;
	signals->sigquit = 0;
	signals->exit = 0;
	signals->pid = 0;
}
