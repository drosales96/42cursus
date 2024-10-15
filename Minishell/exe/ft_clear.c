/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:11:46 by drosales          #+#    #+#             */
/*   Updated: 2024/10/15 11:12:09 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_clear(t_ast *cmd)
{
    if (cmd->left == NULL)
        ft_printf("\033[H\033[J");
    else
    {
        ft_printf("Error : To many arguments for 'clear' command...\n");
        return (ERROR);
    }
    return (OK);
}