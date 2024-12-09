/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:11:46 by drosales          #+#    #+#             */
/*   Updated: 2024/12/09 11:47:35 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_clear(t_ast *cmd)
{
	if (cmd->left == NULL)
		ft_printf("\033[H\033[J");
	else
	{
		ft_printf("error : to many arguments for 'clear' command...\n");
		return (ERROR);
	}
	return (OK);
}

/*int	ft_is_invalid_argument(t_ast *cmd, t_mini *minishell)
{
	if (ft_checker_num(cmd->left->value) == ERROR)
	{
		ft_putendl_fd("exit\nexit: numeric argument is required",
			STDERR_FILENO);
		minishell->final_status = 2;
		return (minishell->final_status);
	}
	return (0);
}*/
