/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:07 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 10:15:32 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_process_token(t_token *tokens, t_ast **ast,
t_ast **current_ast, t_mini *mini)
{
	if (tokens->token_type == TOKEN_COMMAND)
	{
		*current_ast = ft_parsing_cmd(tokens, mini);
		if (!(*current_ast))
			return (0);
		if (!(*ast))
			*ast = *current_ast;
		else
			(*ast)->right = *current_ast;
	}
	else if (tokens->token_type == TOKEN_PIPE)
	{
		*ast = ft_parsing_pipe(tokens, *ast);
		if (!(*ast))
			return (0);
	}
	else if ((tokens->token_type == TOKEN_REDIRECT_IN) \
	|| (tokens->token_type == TOKEN_REDIRECT_OUT) \
	|| (tokens->token_type == TOKEN_REDIRECT_APPEND) \
	|| (tokens->token_type == TOKEN_REDIRECT_HEREDOC))
	{
		*ast = ft_parsing_redirect(tokens, *ast);
	}
	return (1);
}

static int	ft_check_and_update_operators(t_token *tokens,
int *operators_counter, int *heredoc_append_counter, t_ast *ast)
{
	if (ft_is_operator(tokens->token_value))
	{
		(*operators_counter)++;
		if (*operators_counter > 8)
		{
			free_ast(ast);
			return (1);
		}
		if (ft_strcmp(tokens->token_value, "<<") == 0 \
		|| ft_strcmp(tokens->token_value, ">>") == 0)
		{
			(*heredoc_append_counter)++;
			if (*heredoc_append_counter > 3)
			{
				free_ast(ast);
				return (1);
			}
		}
	}
	return (0);
}

t_ast	*ft_making_ast(t_token *tokens, t_mini *mini)
{
	t_ast	*ast;
	t_ast	*current_ast;
	int		operators_counter;
	int		heredoc_append_counter;

	ast = NULL;
	current_ast = NULL;
	operators_counter = 0;
	heredoc_append_counter = 0;
	if (!tokens)
		return (mini->final_status = 0, NULL);
	while (tokens)
	{
		if (ft_checker_sintaxys(tokens, mini) == 1)
			return (free_ast(ast), NULL);
		if (ft_check_and_update_operators(tokens, &operators_counter, \
		&heredoc_append_counter, ast))
			return (NULL);
		if (!ft_process_token(tokens, &ast, &current_ast, mini))
			return (free_ast(ast), NULL);
		tokens = tokens->next;
	}
	return (ast);
}
