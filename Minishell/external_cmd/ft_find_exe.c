/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:38:12 by drosales          #+#    #+#             */
/*   Updated: 2024/12/09 10:57:47 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_find_cmd_in_current_directory(t_ast *cmd)
{
	if (access(cmd->value, F_OK) == 0)
		return (ft_strdup(cmd->value));
	else
		return (NULL);
}

char	*ft_find_cmd_in_path(t_ast *cmd, char **dir)
{
	int		i;
	int		len;
	char	*cmd_path;

	i = 0;
	while (dir[i])
	{
		len = ft_strlen(dir[i]) + ft_strlen(cmd->value) + 2;
		cmd_path = malloc(len);
		if (!cmd_path)
			return (NULL);
		ft_strcpy(cmd_path, dir[i]);
		ft_strcat(cmd_path, "/");
		ft_strcat(cmd_path, cmd->value);
		if (access(cmd_path, F_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*ft_get_path_from_env(t_env *env)
{
	char	*value;

	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
		{
			value = ft_strdup(env->value);
			if (!value)
			{
				ft_printf("error: cannot duplicate PATH value\n");
				return (NULL);
			}
			return (value);
		}
		env = env->next;
	}
	return (NULL);
}
