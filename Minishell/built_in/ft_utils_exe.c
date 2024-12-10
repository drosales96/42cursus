/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:17:11 by drosales          #+#    #+#             */
/*   Updated: 2024/12/04 20:20:41 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c >= 13))
		return (1);
	return (0);
}

void	ft_print_tokens_n(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current != NULL)
	{
		ft_printf("%s", current->token_value);
		if (current->next != NULL)
			ft_printf(" ");
		current = current->next;
	}
}

void	ft_printer_for_echo(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current != NULL)
	{
		ft_printf("%s", current->token_value);
		if (current->next != NULL)
			ft_printf(" ");
		current = current->next;
	}
	ft_printf("\n");
}

void	ft_update_env(t_mini *mini, t_ast *cmd)
{
	t_ast	*current_arg;
	char	*key;
	char	*value;

	current_arg = cmd->left;
	while (current_arg)
	{
		split_env_var(current_arg->value, &key, &value);
		if (!ft_is_valid_env(key))
		{
			ft_printf("export: not valid key\n");
			mini->final_status = 2;
			return ;
		}
		else if (!ft_update_env_key(mini->list_env, key, value))
			ft_env_add(&mini->list_env, key, value);
		current_arg = current_arg->right;
		free(key);
		if (value)
			free(value);
	}
}

char	*ft_find_cmd_path(t_ast *cmd, t_mini *minishell)
{
	char	*path;
	char	**dir;
	char	*result;

	(void)minishell;
	if (!cmd || !cmd->value)
		return (NULL);
	if (cmd->value[0] == '/')
		return (cmd->value);
	if (cmd->value[0] == '.' && cmd->value[1] == '/')
		return (ft_find_cmd_in_current_directory(cmd));
	path = ft_get_path_from_env(minishell->list_env);
	if (!path)
		return (ft_printf("error: $PATH is not in the system\n"), NULL);
	dir = ft_split(path, ':');
	free(path);
	if (!dir)
		return (ft_printf("error: PATH cannot be splited\n"), NULL);
	result = ft_find_cmd_in_path(cmd, dir);
	free_split(dir);
	return (result);
}
