/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:13:36 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 11:50:02 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*int	ft_checker_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (ERROR);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (ERROR);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int	ft_checking_limits_long(char *input)
{
	size_t	len;

	if (ft_checker_num(input) == ERROR)
		return (2);
	len = ft_strlen(input);
	if ((input[0] == '-' && len > 20) || (input[0] != '-' && len > 19))
		return (ERROR);
	if ((input[0] == '-' && ft_strcmp(input, "-9223372036854775808") > 0)
		|| (input[0] != '-' && ft_strcmp(input, "9223372036854775807") > 0))
		return (ERROR);
	return (0);
}

int	ft_str_longcheck(char *str)
{
	int	s;
	int	i;

	s = 0;
	if (str[0] == '-')
		s = -1;
	if (s == -1)
		i = ft_strcmp(LLONGMIN, str);
	else
		i = ft_strcmp(LLONGMAX, str);
	if (i < 0)
		return (-1);
	return (0);
}

int	ft_check_too_many_args(t_ast *cmd, t_mini *minishell)
{
	if (cmd->left->right != NULL)
	{
		ft_putendl_fd("exit\nbash: exit: too many arguments", STDERR_FILENO);
		minishell->final_status = 1;
		return (1);
	}
	return (0);
}

int	ft_exit_no_argument(t_mini *minishell)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	minishell->final_status = 0;
	exit(minishell->final_status);
}*/

int	ft_compare_to_limits(char *str)
{
	int	len;

	len = strlen(str);
	if ((len > MAX_NEG && str[0] == '-') || (len > MAX_DIGITS && str[0] != '-'))
		return (-1);
	if (ft_str_longcheck(str) == -1)
		return (-1);
	return (0);
}

void	ft_exit_no_arguments(t_mini *minishell)
{
	ft_putstr_fd("Successfully exit minishell!\n", STDOUT_FILENO);
	minishell->final_status = 0;
	exit(minishell->final_status);
}

void	ft_exit_invalid_argument(char *arg, t_mini *minishell)
{
	ft_printf("exit\n");
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	minishell->final_status = 2;
	exit(minishell->final_status);
}

int	ft_exit_too_many_arguments(t_mini *minishell)
{
	ft_printf("exit\n");
	ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
	return (minishell->final_status = 1);
}

void	ft_exit_check_limits(char *arg, t_mini *minishell)
{
	if (ft_compare_to_limits(arg) == -1)
	{
		ft_printf("exit\n");
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		minishell->final_status = 2;
		exit(minishell->final_status);
	}
}
