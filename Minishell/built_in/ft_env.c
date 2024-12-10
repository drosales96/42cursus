/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:19:32 by drosales          #+#    #+#             */
/*   Updated: 2024/12/03 15:06:34 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env_cmd(t_ast *cmd, t_mini *minishell)
{
	t_env	*current;

	(void)cmd;
	if (!minishell || !minishell->list_env)
	{
		ft_putstr_fd("error: env: enviropment var list is NULL\n", STDOUT);
		return (ERROR);
	}
	current = minishell->list_env;
	while (current != NULL)
	{
		ft_printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	return (OK);
}
