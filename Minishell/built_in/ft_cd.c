/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:48 by drosales          #+#    #+#             */
/*   Updated: 2024/12/04 19:34:12 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd(t_ast *cmd)
{
	char		cwd[1024];
	char		previous_cwd[1024];
	char		*oldpwd;
	const char	*path;

	if (!getcwd(previous_cwd, sizeof(previous_cwd)))
		return (ft_printf("error: unable to get current directory.\n"), ERROR);
	oldpwd = getenv("PWD");
	path = ft_get_cd_path(cmd);
	if (!path)
		return (ERROR);
	if (ft_chdirectory(path) != 0)
		return (ft_printf("cd: no such file or directory: %s.\n", path), ERROR);
	ft_printf_current_cwd(previous_cwd);
	ft_update_env_vars(oldpwd, cwd);
	return (OK);
}

const char	*ft_get_cd_path(t_ast *cmd)
{
	const char	*oldpwd;

	if (cmd->left == NULL || cmd->left->value == NULL)
		return (getenv("HOME"));
	if (ft_strcmp(cmd->left->value, "-") == 0 \
	|| ft_strcmp(cmd->left->value, "--") == 0)
	{
		oldpwd = getenv("HOME");
		if (oldpwd)
			return (oldpwd);
		else
			return (NULL);
	}
	return (cmd->left->value);
}

int	ft_chdirectory(const char *path)
{
	return (chdir(path));
}

int	ft_printf_current_cwd(const char *previous_cwd)
{
	char	new_cwd[1024];

	if (getcwd(new_cwd, sizeof(new_cwd)) \
	&& ft_strcmp(previous_cwd, new_cwd) != 0)
		return (1);
	return (OK);
}

void	ft_update_env_vars(const char *oldpwd, char *cwd)
{
	setenv("OLDPWD", oldpwd, 1);
	if (getcwd(cwd, sizeof(cwd)))
		setenv("PWD", cwd, 1);
}
