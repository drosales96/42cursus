/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:40:26 by drosales          #+#    #+#             */
/*   Updated: 2024/10/12 11:33:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_is_builtin(t_ast *cmd)
{
    if (cmd == NULL || cmd->value == NULL)
    {
        ft_printf("Error: command not allowed...\n");
        return (ERROR);
    }
    if (ft_strcmp(cmd->value, "cd") == 0)
        ft_cd(cmd);
    else if (ft_strcmp(cmd->value, "pwd") == 0)
        ft_pwd(cmd);
    else if (ft_strcmp(cmd->value, "clear") == 0)
        ft_clear(cmd);
    else if (ft_strcmp(cmd->value, "exit") == 0)
        ft_exit(cmd);
    return (0);
}