/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:26:40 by drosales          #+#    #+#             */
/*   Updated: 2024/12/03 20:04:59 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_command(char *value)
{
	if (ft_is_commands(value))
		return (1);
	return (ft_check_command_access(value));
}

int	ft_is_path(const char *value)
{
	return (
		ft_strchr(value, '*') != NULL \
		|| ft_strchr(value, '/') != NULL \
		|| ft_strchr(value, '~') != NULL \
	);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len] && len < n)
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
