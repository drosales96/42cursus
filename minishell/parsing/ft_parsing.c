/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:46:46 by drosales          #+#    #+#             */
/*   Updated: 2024/12/09 10:15:22 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_ast	*ft_parse_arguments(t_token *tokens)
{
	t_ast	*args_list;
	t_ast	*last_arg;
	t_ast	*arg_node;

	args_list = NULL;
	last_arg = NULL;
	while (tokens && tokens->token_type == TOKEN_ARGUMENT)
	{
		arg_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token_value);
		if (!arg_node)
			return (free_ast(args_list), NULL);
		if (!args_list)
			args_list = arg_node;
		else
			last_arg->right = arg_node;
		last_arg = arg_node;
		tokens = tokens->next;
	}
	return (args_list);
}

t_ast	*ft_parsing_cmd(t_token *tokens, t_mini *mini)
{
	t_ast	*node_cmd;
	t_ast	*args_list;

	if (!tokens || tokens->token_type != TOKEN_COMMAND)
	{
		mini->final_status = 2;
		ft_printf("error: sintax error!\n");
		return (NULL);
	}
	node_cmd = ft_ast_new_node(TOKEN_COMMAND, tokens->token_value);
	if (!node_cmd)
		return (NULL);
	tokens = tokens->next;
	args_list = ft_parse_arguments(tokens);
	if (!args_list && tokens && tokens->token_type == TOKEN_ARGUMENT)
		return (free_ast(node_cmd), NULL);
	node_cmd->left = args_list;
	return (node_cmd);
}

t_ast	*ft_parsing_pipe(t_token *tokens, t_ast *left_cmd)
{
	t_ast	*pipe_node;
	t_ast	*right_cmd;
	t_mini	*mini;

	mini = NULL;
	if (!tokens || tokens->token_type != TOKEN_PIPE)
		return (ft_printf("error: syntax error!\n"), NULL);
	pipe_node = ft_ast_new_node(TOKEN_PIPE, tokens->token_value);
	if (!pipe_node)
		return (ft_printf("error: could not create pipe node\n"), NULL);
	tokens = tokens->next;
	if (!tokens || tokens->token_type != TOKEN_COMMAND)
		return (ft_printf("error: syntax error!\n"), NULL);
	right_cmd = ft_parsing_cmd(tokens, mini);
	if (!right_cmd)
		return (free_ast(pipe_node),
			ft_printf("error: could not parse the right command after pipe\n"),
			NULL);
	pipe_node->left = left_cmd;
	pipe_node->right = right_cmd;
	return (pipe_node);
}

t_ast	*ft_parsing_redirect(t_token *tokens, t_ast *left_cmd)
{
	t_ast	*redirect_node;
	t_ast	*file_node;

	if (!tokens || (tokens->token_type != TOKEN_REDIRECT_IN \
	&& tokens->token_type != TOKEN_REDIRECT_OUT \
	&& tokens->token_type != TOKEN_REDIRECT_APPEND \
	&& tokens->token_type != TOKEN_REDIRECT_HEREDOC))
		return (ft_printf("error: syntax error!\n"), NULL);
	redirect_node = ft_ast_new_node(tokens->token_type, tokens->token_value);
	if (!redirect_node)
		return (ft_printf("error: could not create redirection node\n"), NULL);
	tokens = tokens->next;
	if (!tokens || tokens->token_type != TOKEN_ARGUMENT)
		return (free_ast(redirect_node),
			ft_printf("error: syntax error!\n"), NULL);
	file_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token_value);
	if (!file_node)
		return (free_ast(redirect_node),
			ft_printf("error: could not create file node after redirection\n"),
			NULL);
	redirect_node->left = left_cmd;
	redirect_node->right = file_node;
	return (redirect_node);
}
