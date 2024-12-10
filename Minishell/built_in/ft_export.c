/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:15:10 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 21:45:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_valid_env(char *str)
{
	int	i;

	i = 1;
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_env_key(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '=' && i < BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_update_env_key(t_env *env, char *key, char *value)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	ft_env_add(t_env **env, char *key, char *value)
{
	t_env	*new_node;
	t_env	*current;

	new_node = new_node_env(key, value);
	if (*env == NULL)
		*env = new_node;
	else
	{
		current = *env;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

int	ft_export(t_ast *cmd, t_mini *minishell)
{
	char	**env_array;

	env_array = ft_env_to_array(minishell->list_env);
	if (!env_array || !*env_array)
		return (1);
	if (cmd->left == NULL)
	{
		env_array = ft_env_to_array(minishell->list_env);
		if (!env_array || !*env_array)
			return (1);
		ft_sort_env_array(env_array, ft_str_env_len(env_array));
		ft_print_env_array_sorted(env_array);
		return (0);
	}
	ft_free_2d_array(env_array);
	ft_update_env(minishell, cmd);
	return (0);
}
