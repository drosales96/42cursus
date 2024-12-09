/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:15:50 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 15:38:00 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_env_nodes(t_env *env_list)
{
	int	counter;

	counter = 0;
	while (env_list)
	{
		counter++;
		env_list = env_list->next;
	}
	return (counter);
}

int	ft_str_env_len(char **env_array)
{
	int	i;

	i = 0;
	while (env_array[i])
		i++;
	return (i);
}

void	ft_print_env_array_sorted(char **env_array)
{
	int	i;

	i = 0;
	while (env_array[i] != NULL)
	{
		ft_putstr_fd("declare -x ", STDOUT);
		ft_putendl_fd(env_array[i], STDOUT);
		i++;
	}
}

void	ft_sort_env_array(char **tab, int env_len)
{
	int		ordered;
	int		i;
	char	*tmp;

	ordered = 0;
	while (tab && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		env_len--;
	}
}

char	**ft_env_to_array(t_env *env_list)
{
	int		counter;
	char	**env_array;
	int		i;
	char	*temp;

	temp = NULL;
	counter = ft_count_env_nodes(env_list);
	i = 0;
	env_array = (char **)malloc((counter + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	while (env_list)
	{
		if (env_list->value)
		{
			temp = ft_strjoin(env_list->key, "=");
			env_array[i] = ft_strjoin(temp, env_list->value);
			free(temp);
		}
		else
			env_array[i] = ft_strdup(env_list->key);
		i++;
		env_list = env_list->next;
	}
	return (env_array[i] = NULL, env_array);
}
