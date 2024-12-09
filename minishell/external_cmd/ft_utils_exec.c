/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:44:15 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 17:26:01 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_ast_to_tokens(t_ast *cmd)
{
	t_token	*tokens;
	t_token	*new_token;

	tokens = NULL;
	new_token = NULL;
	while (cmd)
	{
		new_token = malloc(sizeof(t_token));
		if (!new_token)
			return (NULL);
		new_token->token_type = cmd->type;
		new_token->token_value = ft_strdup(cmd->value);
		new_token->next = tokens;
		tokens = new_token;
		if (cmd->left)
			tokens = ft_ast_to_tokens(cmd->left);
		cmd = cmd->right;
	}
	return (tokens);
}

void	ft_print_msg_error(char *prefix, char *cmd_value, char *suffix)
{
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd_value, STDERR_FILENO);
	if (suffix)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(suffix, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	ft_check_path_errors(char *path_cmd, t_mini *mini,
char **list_env, t_ast *cmd)
{
	if (!path_cmd)
	{
		mini->final_status = 127;
		ft_print_msg_error("drosales@marigome_shell:~$", cmd->value,
			"command not found");
		ft_free_2d_array(list_env);
		return (1);
	}
	if (access(path_cmd, F_OK) != 0)
	{
		mini->final_status = 127;
		ft_print_msg_error("drosales@marigome_shell:~$", cmd->value,
			"no such file or directory");
		ft_free_2d_array(list_env);
		return (1);
	}
	if (access(path_cmd, X_OK) != 0)
	{
		mini->final_status = 126;
		ft_print_msg_error("drosales@marigome_shell:~$", cmd->value,
			"permission denied");
		ft_free_2d_array(list_env);
		return (1);
	}
	return (0);
}

char	**ft_ast_to_args(t_ast *cmd)
{
	int		arg_count;
	t_ast	*temp;
	char	**args;

	arg_count = 0;
	temp = cmd->left;
	while (temp)
	{
		arg_count++;
		temp = temp->right;
	}
	args = (char **)malloc(sizeof(char *) * (arg_count + 2));
	if (!args)
		return (NULL);
	args[0] = ft_strdup(cmd->value);
	temp = cmd->left;
	arg_count = 1;
	while (temp)
	{
		args[arg_count] = ft_strdup(temp->value);
		temp = temp->right;
		arg_count++;
	}
	args[arg_count] = NULL;
	return (args);
}

void	ft_reset_flags(t_mini *mini)
{
	mini->redir_flag = -1;
	mini->redir_in_flag = -1;
	mini->heredoc_flag = -1;
}
