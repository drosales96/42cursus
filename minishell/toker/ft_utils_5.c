/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:09:46 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 20:05:51 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	*ft_status(t_mini *mini, int *i)
{
	int	exit_status;

	exit_status = 0;
	exit_status = mini->final_status;
	ft_putnbr_fd(exit_status, STDOUT);
	*i += 2;
	return (i);
}

void	ft_handle_single_quotes(char *value, int *i)
{
	(*i)++;
	while (value[*i] && value[*i] != '\'')
	{
		ft_putchar_fd(value[*i], STDOUT);
		(*i)++;
	}
	if (value[*i] == '\'')
		(*i)++;
}

void	ft_process_argument(char *value, t_mini *minishell)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '\'')
			ft_handle_single_quotes(value, &i);
		else if (value[i] == '"')
			ft_handle_double_quotes(value, &i, minishell);
		else if (value[i] == '$')
			ft_handle_variable_expansion(value, &i, minishell);
		else
			ft_handle_normal_characters(value, &i);
	}
}

int	ft_check_command_access(char *value)
{
	if (access(value, F_OK) == 0)
	{
		if (access(value, X_OK) == 0)
			return (1);
		else
			return (126);
	}
	return (0);
}
