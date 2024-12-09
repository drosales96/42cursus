/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:52:03 by drosales          #+#    #+#             */
/*   Updated: 2024/12/03 15:05:52 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_find_env_var(t_env *list_env, t_env *export_list, char *key)
{
	t_env	*current;

	current = list_env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	current = export_list;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	ft_handle_normal_characters(char *value, int *i)
{
	ft_putchar_fd(value[*i], STDOUT);
	(*i)++;
}

int	ft_echo_cmd(t_ast *cmd, t_mini *minishell)
{
	t_ast	*current_arg;
	int		flag;

	flag = 1;
	current_arg = cmd->left;
	if (current_arg && ft_strcmp(current_arg->value, "-n") == 0)
	{
		flag = 0;
		current_arg = current_arg->right;
	}
	while (current_arg)
	{
		ft_process_argument(current_arg->value, minishell);
		if (current_arg->right)
			ft_putchar_fd(' ', STDOUT);
		current_arg = current_arg->right;
	}
	if (flag)
		ft_putstr_fd("\n", STDOUT);
	return (OK);
}
