/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:18 by drosales          #+#    #+#             */
/*   Updated: 2024/10/15 11:12:40 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_pwd(t_ast *cmd)
{
    char    cwd[1024];

    if (cmd->left != NULL) // SIGNIFICA QUE HAY MAS QUE "PWD"
    {
        ft_printf("Error : PWD must be alone...\n");
        return (ERROR);
    }
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        ft_printf("Error : Value of PWD is NULL...\n");
        return (1);
    }
    ft_putstr_fd(cwd, STDOUT);
    ft_putstr_fd("\n", STDOUT);
    return (OK);
}



