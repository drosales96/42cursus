/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:40:26 by drosales          #+#    #+#             */
/*   Updated: 2024/12/03 14:59:36 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_verify_built_in(t_ast *cmd)
{
	if (ft_strcmp(cmd->value, "cd") == 0
		|| ft_strcmp(cmd->value, "pwd") == 0
		|| ft_strcmp(cmd->value, "clear") == 0
		|| ft_strcmp(cmd->value, "exit") == 0
		|| ft_strcmp(cmd->value, "env") == 0
		|| ft_strcmp(cmd->value, "echo") == 0
		|| ft_strcmp(cmd->value, "unset") == 0
		|| ft_strcmp(cmd->value, "export") == 0)
		return (1);
	return (0);
}

void	ft_is_builtin(t_ast *cmd, t_mini *minishell)
{
	char	**list_env;

	if (cmd == NULL || cmd->value == NULL)
		return ;
	if (ft_strcmp(cmd->value, "cd") == 0)
		minishell->final_status = ft_cd(cmd);
	else if (ft_strcmp(cmd->value, "pwd") == 0)
		minishell->final_status = ft_pwd(cmd);
	else if (ft_strcmp(cmd->value, "clear") == 0)
		minishell->final_status = ft_clear(cmd);
	else if (ft_strcmp(cmd->value, "exit") == 0)
		minishell->final_status = ft_exit(cmd, minishell);
	else if (ft_strcmp(cmd->value, "env") == 0)
		minishell->final_status = ft_env_cmd(cmd, minishell);
	else if (ft_strcmp(cmd->value, "echo") == 0)
		minishell->final_status = ft_echo_cmd(cmd, minishell);
	else if (ft_strcmp(cmd->value, "unset") == 0)
		minishell->final_status = ft_unset_cmd(cmd, minishell);
	else if (ft_strcmp(cmd->value, "export") == 0)
		minishell->final_status = ft_export(cmd, minishell);
	else
	{
		list_env = ft_env_to_array(minishell->list_env);
		ft_execute_fork(cmd, minishell, list_env);
	}
}
