/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:41:36 by marigome          #+#    #+#             */
/*   Updated: 2024/12/04 19:31:55 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_check_redir(t_ast *cmd)
{
	if ((cmd->type == TOKEN_REDIRECT_OUT) \
	|| (cmd->type == TOKEN_REDIRECT_APPEND) \
	|| (cmd->type == TOKEN_REDIRECT_IN) \
	|| (cmd->type == TOKEN_REDIRECT_HEREDOC))
		return (1);
	return (0);
}

void	ft_execute_in(t_mini *mini, t_ast *cmd, int fd)
{
	if (mini->redir_in_flag == -1)
	{
		mini->redir_in_flag = 1;
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("error: fd is duplicated wrongly\n");
			close(fd);
			exit(EXIT_FAILURE);
		}
		close(fd);
	}
	ft_exec_ast(mini, cmd->left);
	exit(EXIT_SUCCESS);
}

void	ft_execute_out(t_mini *mini, t_ast *cmd, int fd)
{
	if (mini->redir_flag == -1)
	{
		mini->redir_flag = 1;
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("error: fd is duplicated wrongly\n");
			close(fd);
			exit(EXIT_FAILURE);
		}
		close(fd);
	}
	ft_exec_ast(mini, cmd->left);
	exit(EXIT_SUCCESS);
}

t_ast	*ft_type_of_redir(t_ast *cmd, t_mini *mini)
{
	if (cmd->type == TOKEN_REDIRECT_HEREDOC)
	{
		ft_heredoc(cmd, mini);
		cmd = cmd->left;
	}
	else if (cmd->type == TOKEN_REDIRECT_IN)
	{
		ft_redirect_in(cmd, mini);
		cmd = cmd->left;
	}
	else if (cmd->type == TOKEN_REDIRECT_OUT)
	{
		ft_redirect_out(cmd, mini);
		cmd = cmd->left;
	}
	else if (cmd->type == TOKEN_REDIRECT_APPEND)
	{
		ft_redirect_append(cmd, mini);
		cmd = cmd->left;
	}
	return (cmd);
}
