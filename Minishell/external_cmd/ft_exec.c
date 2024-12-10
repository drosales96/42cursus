/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:54:06 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 10:59:56 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**ft_prepare_execution(t_ast *cmd, t_mini *minishell)
{
	char	**args;
	int		i;
	char	*status_str;

	args = ft_ast_to_args(cmd);
	if (!args)
		return (NULL);
	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], "$?") == 0)
		{
			status_str = ft_itoa(minishell->final_status);
			if (!status_str)
			{
				ft_free_2d_array(args);
				return (NULL);
			}
			free(args[i]);
			args[i] = status_str;
		}
		i++;
	}
	return (args);
}

static void	ft_execute_child_process(char *path_cmd,
char **args, char **list_env)
{
	execve(path_cmd, args, list_env);
	perror("execve falló");
	ft_free_2d_array(args);
	free(path_cmd);
	ft_free_2d_array(list_env);
	exit(127);
}

static void	ft_wait_and_update_status(t_mini *minishell, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	minishell->exit = WEXITSTATUS(status);
	if (WIFEXITED(status))
		minishell->final_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		minishell->final_status = 128 + WTERMSIG(status);
}

int	ft_execute_fork(t_ast *cmd, t_mini *minishell, char **list_env)
{
	pid_t	pid;
	char	**args;
	char	*path_cmd;

	path_cmd = ft_find_cmd_path(cmd, minishell);
	if (ft_check_path_errors(path_cmd, minishell, list_env, cmd))
		return (free(path_cmd), 1);
	args = ft_prepare_execution(cmd, minishell);
	if (!args)
		return (free(path_cmd), EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork falló");
		ft_free_2d_array(args);
		free(path_cmd);
		return (EXIT_FAILURE);
	}
	if (pid == 0)
		ft_execute_child_process(path_cmd, args, list_env);
	ft_wait_and_update_status(minishell, pid);
	ft_free_three(args, list_env);
	return (minishell->exit);
}

void	ft_exec_ast(t_mini *minishell, t_ast *ast)
{
	if (!ast)
		return ;
	if (ft_check_redir(ast) == 1)
		ft_type_of_redir(ast, minishell);
	if (ast->type == TOKEN_COMMAND)
		ft_is_builtin(ast, minishell);
	else if (ast->type == TOKEN_PIPE)
		ft_pipe(ast, minishell);
}
