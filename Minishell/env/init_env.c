/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:43:11 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 10:25:24 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*new_node_env(char *key, char *path)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(key);
	if (!new_node->key)
		return (ft_free_node_env(new_node), NULL);
	if (path)
	{
		new_node->value = ft_strdup(path);
		if (!new_node->value)
		{
			free(new_node->key);
			free(new_node);
			return (NULL);
		}
	}
	else
		new_node->value = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	split_env_var(const char *env, char **key, char **path)
{
	int		key_len;
	char	*find_equal;

	find_equal = ft_strchr(env, '=');
	if (!find_equal)
		return ;
	if (find_equal)
	{
		key_len = find_equal - env;
		*key = ft_substr(env, 0, key_len);
		*path = ft_strdup(find_equal + 1);
	}
	else
	{
		*key = ft_strdup(env);
		*path = NULL;
	}
}

void	ft_free_env_node(t_env *head, char *key, char *value)
{
	free_env(head);
	if (key)
	{
		free(key);
		key = NULL;
	}
	if (value)
	{
		free(value);
		value = NULL;
	}
	return ;
}

static t_env	*ft_node_linking(char *env_var, t_env **head, t_env **current)
{
	char	*key;
	char	*value;
	t_env	*new_node;

	key = NULL;
	value = NULL;
	split_env_var(env_var, &key, &value);
	new_node = new_node_env(key, value);
	free(key);
	if (value)
		free(value);
	if (!new_node)
	{
		ft_free_env_node(*head, NULL, NULL);
		return (NULL);
	}
	if (!*head)
		*head = new_node;
	else
		(*current)->next = new_node;
	*current = new_node;
	return (new_node);
}

t_env	*init_env_list(char **envp)
{
	t_env	*head;
	t_env	*current;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (envp[i])
	{
		if (!ft_node_linking(envp[i], &head, &current))
		{
			free_env(head);
			free_env(current);
			return (NULL);
		}
		i++;
	}
	return (head);
}
