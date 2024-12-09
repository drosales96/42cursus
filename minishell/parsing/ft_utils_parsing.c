/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:24:33 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 10:36:14 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_ast	*ft_ast_new_node(t_token_type type, char *value)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
	{
		ft_printf("error: ast three is undefined!\n");
		return (NULL);
	}
	node->type = type;
	node->value = ft_strdup(value);
	if (node->value == NULL)
		return (free_ast(node), NULL);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	ft_checker_sintaxys(t_token *tokens, t_mini *mini)
{
	if (!mini)
		return (ft_printf("error: mini is NULL\n"), 1);
	while (tokens)
	{
		if ((tokens->token_type == TOKEN_PIPE \
		|| tokens->token_type == TOKEN_REDIRECT_IN \
		||tokens->token_type == TOKEN_REDIRECT_OUT \
		|| tokens->token_type == TOKEN_REDIRECT_APPEND \
		|| tokens->token_type == TOKEN_REDIRECT_HEREDOC) \
		&& (!tokens->prev || tokens->prev->token_type == TOKEN_PIPE \
		|| tokens->prev->token_type == TOKEN_REDIRECT_IN \
		|| tokens->prev->token_type == TOKEN_REDIRECT_OUT \
		|| tokens->prev->token_type == TOKEN_REDIRECT_APPEND \
		|| tokens->prev->token_type == TOKEN_REDIRECT_HEREDOC))
		{
			ft_printf("error: syntax error!\n");
			mini->final_status = 2;
			return (1);
		}
		tokens = tokens->next;
	}
	return (0);
}

t_ast	*ft_parsing_args(t_token *tokens)
{
	t_ast	*arg_node;

	if (tokens->token_type == TOKEN_ARGUMENT)
	{
		arg_node = ft_ast_new_node(TOKEN_ARGUMENT, tokens->token_value);
		if (!arg_node)
			return (NULL);
		tokens = tokens->next;
	}
	else
	{
		ft_printf("error: syntax error!\n");
		return (NULL);
	}
	return (arg_node);
}

int	ft_is_operator(const char *token)
{
	return (ft_strcmp(token, "|") == 0 \
		|| ft_strcmp(token, ">") == 0 \
		|| ft_strcmp(token, "<") == 0 \
		|| ft_strcmp(token, ">>") == 0 \
		|| ft_strcmp(token, "<<") == 0);
}
