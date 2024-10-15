/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:26:40 by drosales          #+#    #+#             */
/*   Updated: 2024/10/10 15:07:31 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_isallsimbols(int c) 
{
    if (c == '\'' || c == '\"' || c == '<' || c == '>' || c == '|')
        return (1);
    return (0);
}

int ft_is_command(const char *value) 
{
    return (
        ft_strcmp(value, "ls") == 0 ||
        ft_strcmp(value, "cat") == 0 ||
        ft_strcmp(value, "echo") == 0 ||
        ft_strcmp(value, "cd") == 0 ||
        ft_strcmp(value, "export") == 0 ||
        ft_strcmp(value, "pwd") == 0 ||
        ft_strcmp(value, "grep") == 0 ||
        ft_strcmp(value, "unset") == 0 ||
        ft_strcmp(value, "env") == 0 ||
        ft_strcmp(value, "exit") == 0 ||
        ft_strcmp(value, "clear") == 0
    );
}

int ft_is_operator(const char *value) 
{
    return (
        ft_strcmp(value, "|") == 0 ||
        ft_strcmp(value, "<") == 0 ||
        ft_strcmp(value, ">") == 0 ||
        ft_strcmp(value, "<<") == 0 ||
        ft_strcmp(value, ">>") == 0
    );
}

int ft_is_path(const char *value) 
{
    return (
        ft_strchr(value, '*') != NULL ||
        ft_strchr(value, '/') != NULL ||
        ft_strchr(value, '~') != NULL
    );
}
