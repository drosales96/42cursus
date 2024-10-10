/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:46:46 by drosales          #+#    #+#             */
/*   Updated: 2024/10/10 17:08:44 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_ast   *ft_parsing_path(token_list *tokens)
{
    t_ast   *path_node;

    if (tokens->token.token_type == TOKEN_PATH)
    {
        path_node = ft_ast_new_node(TOKEN_PATH, tokens->token.token_value);
        if (!path_node)
            return (NULL);
        tokens = tokens->next;
    }
    else
    {
        ft_printf("Syntax Error: Expected a path\n");
        return (NULL);
    }
    return (path_node);
}

t_ast   *ft_parsing_args(token_list *tokens)
{    
    t_ast   *arg_node;

    if (tokens->token.token_type == TOKEN_ARGUMENT)
    {
        arg_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token.token_value);
        if (!arg_node)
            return (NULL);
        tokens = tokens->next;
    }
    else
    {
        ft_printf("Syntax Error: Expected an argument\n");
        return (NULL);
    }
    return (arg_node);
}

t_ast   *ft_parsing_cmd(token_list *tokens)
{
    t_ast   *arg_node;
    t_ast   *node_cmd;
    t_ast   *args_list;
    t_ast   *last_arg;

    if (!tokens || tokens->token.token_type != TOKEN_COMMAND)
    {
        ft_printf("Sintax Error : A command was expected!\n");
        return (NULL);
    }
    if (!ft_is_command(tokens->token.token_value))
    {
        ft_printf("Error: '%s' is not a valid command\n", tokens->token.token_value);
        return (NULL);
    }
    node_cmd = ft_ast_new_node(TOKEN_COMMAND, tokens->token.token_value);
    tokens = tokens->next;
    args_list = NULL;
    last_arg = NULL;
    while (tokens && tokens->token.token_type == TOKEN_ARGUMENT)
    {
        arg_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token.token_value);
        if (!arg_node)
            return (NULL);
        if (!args_list)
            args_list = arg_node;
        else
            last_arg->right = arg_node;
        last_arg = arg_node;
        tokens = tokens->next;
    }
    if (tokens && tokens->token.token_type == TOKEN_PATH)
        node_cmd->right = ft_parsing_path(tokens);
    return (node_cmd);
}

t_ast   *ft_parsing_operator(token_list *tokens, t_ast *left_cmd)
{
    t_ast   *right_cmd;
    t_ast   *operator_node;

    operator_node = NULL;
    right_cmd = NULL;
        if (tokens && tokens->token.token_type == TOKEN_OPERATOR)
        {
            if ((ft_strcmp(tokens->token.token_value, ">") == 0) && tokens->next &&
                (ft_strcmp(tokens->next->token.token_value, ">") == 0))
            {
                tokens = tokens->next;
                operator_node = ft_ast_new_node(TOKEN_OPERATOR, ">>");
                tokens = tokens->next;
            }
            if ((ft_strcmp(tokens->token.token_value, "<") == 0) && tokens->next &&
                (ft_strcmp(tokens->next->token.token_value, "<") == 0))
            {
                tokens = tokens->next;
                operator_node = ft_ast_new_node(TOKEN_OPERATOR, "<<");
                tokens = tokens->next;
            }
            else
            {
                operator_node = ft_ast_new_node(TOKEN_OPERATOR, tokens->token.token_value);
                if (!operator_node)
                    return (NULL);
                tokens = tokens->next;
            }
            if (ft_strcmp(operator_node->value, "|") == 0)
            {
                if (tokens && tokens->token.token_type == TOKEN_COMMAND)
                {
                    right_cmd = ft_parsing_cmd(tokens);
                    operator_node->right = right_cmd;
                }
                else
                {
                    ft_printf("Syntax Error: Expected a command after pipe!\n");
                    return (NULL);
                }
            }
            else if ((ft_strcmp(operator_node->value, ">") == 0 || ft_strcmp(operator_node->value, ">>") == 0 ||
                 ft_strcmp(operator_node->value, "<") == 0 || ft_strcmp(operator_node->value, "<<") == 0))
            {
                if (tokens && tokens->token.token_type == TOKEN_PATH)
                {
                    right_cmd = ft_parsing_path(tokens);
                    operator_node->right = right_cmd;
                }
                else if (tokens && tokens->token.token_type == TOKEN_ARGUMENT)
                {
                    right_cmd = ft_parsing_args(tokens);
                    operator_node->right = right_cmd;
                }
                else
                {
                    ft_printf("Syntax Error: Expected a file or path after redirection!\n");
                    return (NULL);
                }
            }
            else
            {
                ft_printf("Unknown operator: %s\n", operator_node->value);
                return (NULL);
            }
            operator_node->left = left_cmd;
        }
        return (operator_node);
}

