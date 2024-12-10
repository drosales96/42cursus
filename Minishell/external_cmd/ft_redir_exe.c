/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:27 by drosales          #+#    #+#             */
/*   Updated: 2024/12/04 19:25:24 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirect_in(t_ast *cmd, t_mini *mini)
{
	int		fd;
	pid_t	pid;

	fd = open(cmd->right->value, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error: cannot open the file\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("error: fork: not foking for now\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		ft_execute_in(mini, cmd, fd);
	close(fd);
	waitpid(pid, NULL, 0);
}

void	ft_redirect_out(t_ast *cmd, t_mini *mini)
{
	int		fd;
	pid_t	pid;

	if (!cmd || !cmd->right || !cmd->right->value)
	{
		ft_printf("error: invalid redir out\n");
		return ;
	}
	fd = open(cmd->right->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("error: cannot open the file\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		ft_execute_out(mini, cmd, fd);
	close(fd);
	waitpid(pid, NULL, 0);
}

void	ft_redirect_append(t_ast *ast, t_mini *minishell)
{
	int		fd;
	pid_t	pid;

	if (!ast || !ast->right || !ast->right->value)
	{
		ft_printf("error: invalid append\n");
		return ;
	}
	fd = open(ast->right->value, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("error: cannot open the file\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("error: fork: not foking for now\n");
		close(fd);
		return ;
	}
	else if (pid == 0)
		ft_execute_out(minishell, ast, fd);
	waitpid(pid, NULL, 0);
	close(fd);
}
