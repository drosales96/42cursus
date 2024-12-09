/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:53:58 by marigome          #+#    #+#             */
/*   Updated: 2024/12/04 19:25:30 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_handle_heredoc_child(t_ast *cmd, int *fd)
{
	char	*input;

	close(fd[0]);
	while (1)
	{
		input = readline("> ");
		if (!input || ft_strcmp(input, cmd->right->value) == 0)
		{
			free(input);
			break ;
		}
		if (*input != '\0')
		{
			write(fd[1], input, ft_strlen(input));
			write(fd[1], "\n", 1);
		}
		free(input);
	}
	close(fd[1]);
	exit(EXIT_SUCCESS);
}

static void	ft_handle_her_parent(t_mini *mini, int *fd, pid_t pid, t_ast *cmd)
{
	close(fd[1]);
	waitpid(pid, NULL, 0);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("error: fd is duplicated\n");
		close(fd[0]);
		return ;
	}
	close(fd[0]);
	ft_exec_ast(mini, cmd->left);
}

void	ft_heredoc(t_ast *cmd, t_mini *mini)
{
	int		fd[2];
	pid_t	pid;

	if (!cmd || !cmd->right || !cmd->right->value)
	{
		ft_printf("error: invalid heredoc\n");
		return ;
	}
	if (pipe(fd) == -1)
	{
		perror("error: pipe conection hor heredoc is not working\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("error: fork: not foking for now\n");
		close(fd[0]);
		close(fd[1]);
		return ;
	}
	if (pid == 0)
		ft_handle_heredoc_child(cmd, fd);
	ft_handle_her_parent(mini, fd, pid, cmd);
}
