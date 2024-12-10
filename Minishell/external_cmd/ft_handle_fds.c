/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:03:11 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 15:51:25 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_reset_std(t_mini *mini)
{
	dup2(mini->ministdin, STDIN_FILENO);
	dup2(mini->ministdout, STDOUT_FILENO);
}

void	ft_close_fds(t_mini *mini)
{
	ft_close(mini->ministdin);
	ft_close(mini->ministdout);
}

void	ft_reset_fds(t_mini *mini)
{
	mini->ministdin = dup2(mini->ministdin, STDIN_FILENO);
	mini->ministdout = dup2(mini->ministdout, STDOUT_FILENO);
}
