/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:40:24 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 17:36:43 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_mini	*init_mini(char **env)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->list_env = init_env_list(env);
	if (!mini->list_env)
		return (free_mini(mini), NULL);
	mini->env = env;
	mini->ministdin = dup(STDIN_FILENO);
	mini->ministdout = dup(STDOUT_FILENO);
	mini->line = NULL;
	mini->tokens = NULL;
	mini->exit = 0;
	mini->heredoc_flag = 0;
	return (mini);
}
