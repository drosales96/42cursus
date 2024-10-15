/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:46:46 by drosales          #+#    #+#             */
/*   Updated: 2024/10/14 11:47:11 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


t_ast   *ft_parsing_args(Token *tokens)
{    
    t_ast   *arg_node;

    if (tokens->token_type == TOKEN_ARGUMENT)
    {
        arg_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token_value);
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

t_ast   *ft_parsing_cmd(Token *tokens)
{
    t_ast   *arg_node;
    t_ast   *node_cmd;
    t_ast   *args_list;
    t_ast   *last_arg;

    if (!tokens || tokens->token_type != TOKEN_COMMAND)
    {
        ft_printf("Sintax Error : A command was expected!\n");
        return (NULL);
    }
    if (!ft_is_command(tokens->token_value))
    {
        ft_printf("Error: '%s' is not a valid command\n", tokens->token_value);
        return (NULL);
    }
    node_cmd = ft_ast_new_node(TOKEN_COMMAND, tokens->token_value);
    ft_printf("Parsing command: %s (AST node: %p)\n", tokens->token_value, node_cmd);
    tokens = tokens->next;
    args_list = NULL;
    last_arg = NULL;
    while (tokens && tokens->token_type == TOKEN_ARGUMENT)
    {
        arg_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token_value);
        if (!arg_node)
            return (NULL);
        if (!args_list)
            args_list = arg_node;
        else
            last_arg->right = arg_node;
        ft_printf("Adding argument: %s (AST node: %p)\n", tokens->token_value, arg_node);
        last_arg = arg_node;
        tokens = tokens->next;
    }
    node_cmd->left = args_list;
    ft_printf("Command %s (AST node: %p) has arguments (left node: %p)\n", node_cmd->value, node_cmd, node_cmd->left);
    return (node_cmd);
}

t_ast *ft_parsing_pipe(Token *tokens, t_ast *left_cmd)
{
    t_ast *pipe_node;
    t_ast *right_cmd;
    if (!tokens || tokens->token_type != TOKEN_PIPE)
    {
        ft_printf("Syntax Error: A pipe '|' was expected!\n");
        return (NULL);
    }
    pipe_node = ft_ast_new_node(TOKEN_PIPE, tokens->token_value);
    ft_printf("Parsing pipe: %s (AST node: %p)\n", tokens->token_value, pipe_node);
    if (!pipe_node)
    {
        ft_printf("Error: Could not create pipe node\n");
        return (NULL);
    }
    tokens = tokens->next;
    if (!tokens || tokens->token_type != TOKEN_COMMAND)
    {
        ft_printf("Syntax Error: Expected a command after pipe '|'!\n");
        return (NULL);
    }
    right_cmd = ft_parsing_cmd(tokens);
    if (!right_cmd)
    {
        ft_printf("Error: Could not parse the right command after pipe\n");
        return (NULL);
    }
    pipe_node->left = left_cmd;
    pipe_node->right = right_cmd;
    ft_printf("Pipe node (AST node: %p) has left command: %p and right command: %p\n", pipe_node, left_cmd, right_cmd);
    return (pipe_node);
}

t_ast *ft_parsing_redirect(Token *tokens, t_ast *left_cmd)
{
    t_ast *redirect_node;
    t_ast *file_node;
    if (!tokens || (tokens->token_type != TOKEN_REDIRECT_IN && 
                    tokens->token_type != TOKEN_REDIRECT_OUT &&
                    tokens->token_type != TOKEN_REDIRECT_APPEND &&
                    tokens->token_type != TOKEN_REDIRECT_HEREDOC))
    {
        ft_printf("Syntax Error: A redirection operator was expected!\n");
        return (NULL);
    }
    redirect_node = ft_ast_new_node(tokens->token_type, tokens->token_value);
    if (!redirect_node)
    {
        ft_printf("Error: Could not create redirection node\n");
        return (NULL);
    }
    tokens = tokens->next;
    if (!tokens || tokens->token_type != TOKEN_ARGUMENT)
    {
        ft_printf("Syntax Error: Expected a file or path after redirection!\n");
        return (NULL);
    }
    file_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token_value);
    if (!file_node)
    {
        ft_printf("Error: Could not create file node after redirection\n");
        return (NULL);
    }
    redirect_node->left = left_cmd;
    redirect_node->right = file_node;

    return (redirect_node);
}

