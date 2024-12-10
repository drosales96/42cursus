/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:52:09 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 10:02:57 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_empty_tok_out(t_token *tokens)
{
	if (ft_strcmp(tokens->token_value, "") == 0 \
	|| ft_strcmp(tokens->token_value, " ") == 0)
		tokens->token_type = TOKEN_EMPTY;
	ft_printf("error: parser: there is an empty token\n");
	return ;
}

t_token	*read_tokens(char *line, int *index)
{
	t_token	*token;

	token = ft_token_size();
	token->token_value = ft_size_token_value(line, index, token);
	token->token_value = ft_token_value(line, index, token);
	if (!token->token_value)
		free_tokens(token);
	return (token);
}

void	ft_update_type_tokens(t_token *token)
{
	if (ft_strcmp(token->token_value, "") == 0)
		ft_empty_tok_out(token);
	else if (ft_strcmp(token->token_value, ">") == 0)
		token->token_type = TOKEN_REDIRECT_OUT;
	else if (ft_strcmp(token->token_value, "<") == 0)
		token->token_type = TOKEN_REDIRECT_IN;
	else if (ft_strcmp(token->token_value, ">>") == 0)
		token->token_type = TOKEN_REDIRECT_APPEND;
	else if (ft_strcmp(token->token_value, "<<") == 0)
		token->token_type = TOKEN_REDIRECT_HEREDOC;
	else if (ft_strcmp(token->token_value, "|") == 0)
		token->token_type = TOKEN_PIPE;
	else if (token->prev != NULL && (
			token->prev->token_type == TOKEN_REDIRECT_IN \
		|| token->prev->token_type == TOKEN_REDIRECT_OUT \
		|| token->prev->token_type == TOKEN_REDIRECT_APPEND \
		|| token->prev->token_type == TOKEN_REDIRECT_HEREDOC))
		token->token_type = TOKEN_ARGUMENT;
	else if (token->prev == NULL || token->prev->token_type == TOKEN_PIPE)
		token->token_type = TOKEN_COMMAND;
	else if (token->prev->token_type == TOKEN_COMMAND)
		token->token_type = TOKEN_ARGUMENT;
	else
		token->token_type = TOKEN_ARGUMENT;
}

t_token	*get_tokens(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		i;

	prev = NULL;
	next = NULL;
	i = 0;
	ft_pass_spaces(line, &i);
	while (line[i])
	{
		next = read_tokens(line, &i);
		if (!next)
			return (free_tokens(prev), NULL);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		ft_update_type_tokens(next);
		ft_pass_spaces(line, &i);
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}

t_ast	*ft_parse(t_mini *minishell)
{
	t_ast	*ast;

	ast = NULL;
	sig_init();
	minishell->redir_flag = -1;
	minishell->redir_in_flag = -1;
	if (!ft_read_and_validate_line(minishell))
		return (NULL);
	ast = ft_process_tokens(minishell);
	if (!ast)
		return (free(ast), NULL);
	free(minishell->line);
	return (ast);
}
