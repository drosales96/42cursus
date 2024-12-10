/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:26:15 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 10:43:22 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_mini(t_mini *mini)
{
	if (!mini)
		return ;
	if (mini->env)
		ft_free_2d_array(mini->env);
	if (mini->list_env)
		free_env(mini->list_env);
	if (mini->export_list)
		free_env(mini->export_list);
	if (mini->line)
		free(mini->line);
	if (mini->tokens)
		free_tokens(mini->tokens);
	free(mini);
}

void	ft_free_node_env(t_env *node)
{
	free(node->key);
	free(node);
}
