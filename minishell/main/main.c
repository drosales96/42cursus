/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:01:18 by drosales          #+#    #+#             */
/*   Updated: 2024/12/09 08:56:45 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_signal	g_signals;

int	main(int ac, char **argv, char **env)
{
	t_mini	*minishell;
	t_ast	*cmd_ast;

	(void)ac;
	(void)argv;
	init_signals(&g_signals);
	sig_init();
	minishell = init_mini(env);
	if (!minishell)
		return (clear_history(), EXIT_FAILURE);
	while (!g_signals.exit)
	{
		cmd_ast = ft_parse(minishell);
		if (cmd_ast)
		{
			if (cmd_ast->value)
				ft_exec_ast(minishell, cmd_ast);
			free_ast(cmd_ast);
		}
		ft_reset_std(minishell);
	}
	free_mini(minishell);
	clear_history();
	return (0);
}
