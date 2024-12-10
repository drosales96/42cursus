/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:34:01 by marigome          #+#    #+#             */
/*   Updated: 2024/12/04 19:25:45 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static pid_t	ft_execute_left_pipe(t_ast *cmd, t_mini *mini, int *fd)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("error: fork: not foking for now\n");
		return (-1);
	}
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_exec_ast(mini, cmd->left);
		exit(0);
	}
	return (pid1);
}

static pid_t	ft_execute_right_pipe(t_ast *cmd, t_mini *mini, int *fd)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("error: fork: not foking for now\n");
		return (-1);
	}
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_exec_ast(mini, cmd->right);
		exit(0);
	}
	return (pid2);
}

void	ft_pipe(t_ast *cmd, t_mini *mini)
{
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
	{
		perror("error: invalid pipeline\n");
		return ;
	}
	if (ft_check_redir(cmd->left) == 1)
		ft_type_of_redir(cmd->left, mini);
	pid1 = ft_execute_left_pipe(cmd, mini, fd);
	pid2 = ft_execute_right_pipe(cmd, mini, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	if (WIFEXITED(status))
		mini->exit = WEXITSTATUS(status);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		mini->exit = WEXITSTATUS(status);
}
