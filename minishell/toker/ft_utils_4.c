/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:27:40 by marigome          #+#    #+#             */
/*   Updated: 2024/12/09 19:46:08 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_token_size(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->token_value = NULL;
	token->next = NULL;
	return (token);
}

char	*ft_size_token_value(char *line, int *index, t_token *token)
{
	token->token_value = malloc(sizeof(char) * token_size(line, index) + 1);
	if (!token->token_value)
	{
		free(token);
		return (NULL);
	}
	return (token->token_value);
}

char	*ft_token_value(char *line, int *index, t_token *token)
{
	char	quote_char;
	int		i;

	quote_char = ' ';
	i = 0;
	while (line[*index] && (line[*index] != ' ' || quote_char != ' '))
	{
		if ((line[*index] == '"' || line[*index] == '\'') && quote_char == ' ')
		{
			quote_char = line[*index];
			token->token_value[i++] = line[(*index)++];
			continue ;
		}
		if (line[*index] == quote_char)
		{
			token->token_value[i++] = line[(*index)++];
			quote_char = ' ';
			continue ;
		}
		token->token_value[i++] = line[(*index)++];
	}
	token->token_value[i] = '\0';
	return (token->token_value);
}

int	ft_read_and_validate_line(t_mini *minishell)
{
	minishell->line = readline("drosales@marigome_shell:~$ ");
	if (!minishell->line)
	{
		minishell->exit = 1;
		ft_putendl_fd("exit", STDOUT_FILENO);
		free_tokens(minishell->tokens);
		free(minishell->line);
		minishell->tokens = NULL;
		exit(0);
	}
	if (*minishell->line)
		add_history(minishell->line);
	if (ft_checker_quotes_unclosed(minishell))
	{
		free(minishell->line);
		minishell->line = NULL;
		return (0);
	}
	return (1);
}

t_ast	*ft_process_tokens(t_mini *minishell)
{
	t_ast	*ast;

	ast = NULL;
	if (minishell->tokens)
	{
		free_tokens(minishell->tokens);
		minishell->tokens = NULL;
	}
	minishell->tokens = get_tokens(minishell->line);
	if (!minishell->tokens)
	{
		free(minishell->line);
		minishell->line = NULL;
		return (NULL);
	}
	ast = ft_making_ast(minishell->tokens, minishell);
	return (ast);
}
