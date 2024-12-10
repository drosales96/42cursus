/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:52:47 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 11:56:32 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*static int	ft_process_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static long long	ft_util_atol(long long result, char c, int sign)
{
	if (result > LLONG_MAX / 10 \
	|| (result == LLONG_MAX / 10 && (c - '0') > LLONG_MAX % 10))
	{
		if (sign == 1)
			return (LLONG_MAX);
		else
			return (LLONG_MIN);
	}
	return (result * 10 + (c - '0'));
}

static long long	ft_atol(char *str)
{
	long long	result;
	long long	temp;
	int			sign;
	int			i;

	result = 0;
	temp = 0;
	sign = 1;
	i = ft_process_sign(str, &sign);
	if (str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = ft_util_atol(result, str[i], sign);
		if (temp == LLONG_MAX || temp == LLONG_MIN)
			return (temp);
		result = temp;
		i++;
	}
	return (result * sign);
}

int	ft_exit(t_ast *cmd, t_mini *minishell)
{
	long long	exit_value;

	if (cmd->left == NULL)
		return (ft_exit_no_argument(minishell));
	if (ft_str_longcheck(cmd->left->value) == -1)
	{
		ft_putendl_fd("exit\nexit: numeric argument is required",
			STDERR_FILENO);
		minishell->final_status = 2;
		exit(minishell->final_status);
	}
	if (ft_is_invalid_argument(cmd, minishell))
		exit(minishell->final_status);
	if (ft_check_too_many_args(cmd, minishell))
		return (minishell->final_status);
	if (ft_checking_limits_long(cmd->left->value) == ERROR)
		exit(minishell->final_status = 255);
	exit_value = ft_atol(cmd->left->value);
	minishell->final_status = exit_value % 256;
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(minishell->final_status);
}*/

static long long	ft_atol(char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	ft_checker_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
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

int	ft_exit(t_ast *ast, t_mini *minishell)
{
	long long	exit_value;

	if (ast->left == NULL)
		ft_exit_no_arguments(minishell);
	if (ft_checker_number(ast->left->value) == -1)
		ft_exit_invalid_argument(ast->left->value, minishell);
	if (ast->left->right != NULL)
		return (ft_exit_too_many_arguments(minishell));
	ft_exit_check_limits(ast->left->value, minishell);
	exit_value = ft_atol(ast->left->value);
	minishell->final_status = exit_value % 256;
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(minishell->final_status);
}
