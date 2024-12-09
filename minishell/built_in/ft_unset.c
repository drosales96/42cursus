/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:06:33 by drosales          #+#    #+#             */
/*   Updated: 2024/12/04 19:37:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// # ======= VERIFICAR INPUT ========= #

int	ft_find_var(t_env *env, char *key)
{
	t_env	*current;
	t_env	*previous;

	current = env;
	previous = NULL;
	if (!current)
		return (ft_putstr_fd("error: unset: envlist is not working\n", STDOUT),
			ERROR);
	while (current != NULL)
	{
		if (ft_strcmp(key, current->key) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				env = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return (OK);
		}
		previous = current;
		current = current->next;
	}
	return (ERROR);
}

int	ft_unset_cmd(t_ast *cmd, t_mini *minishell)
{
	char	*key;

	if (!cmd)
		return (ft_putstr_fd("error unset\n", STDOUT), ERROR);
	if (cmd->left == NULL || cmd->left->value == NULL)
		return (ERROR);
	if (cmd->left != NULL && cmd->left->right != NULL)
		return (ft_printf("error: unset: too many arguments\n"), ERROR);
	key = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!key)
		return (ERROR);
	if (ft_is_valid_env(cmd->left->value) == 1)
	{
		ft_get_env_key(key, cmd->left->value);
		if (ft_find_var(minishell->list_env, key) == OK)
			ft_printf("you have unset %s correctly\n", key);
		else
			ft_printf("error: cannot found '%s'.\n", key);
	}
	else
		ft_printf("error: invalid variable\n");
	free(key);
	return (OK);
}
