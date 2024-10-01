/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:22:38 by drosales          #+#    #+#             */
/*   Updated: 2024/10/01 13:00:24 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_take_element_between_quotes(char *input, int *i)
{
    char    quote;
    char    *start;
    char    *token;

    quote = input[*i];
    (*i)++;
    start = &input[*i];
    while (input[*i] && input[*i] != quote)
        (*i)++;
    token = ft_strndup(start, *i - (start - &input[*i]));
    if (input[*i] == quote)
        (*i)++;
    return (token);
}

t_list  *ft_lexer(char  *input)
{
    int         i;
    t_list      *tokens;

    i = 0;
    tokens = NULL;
    while (input[i])
    {
        if (ft_isspace(input[i]))
        {    
            i++;
            continue;
        }
        if (ft_isallsimbols(input[i]))
            ft_lexing_operators(input, &i, &tokens);
        else
            ft_lexing_words(input, &i, &tokens);
    }    
    return (tokens);
}

void  *ft_lexing_operators(char *input, int *i, t_list **tokens)
{
    char        operators[3];
    Token_type  type;

    if (input[*i] == '<' && input[*i + 1] == '<' || input[*i] == '>' && input[*i + 1] == '>' )
    {
        operators[0] = input[*i];
        operators[1] = input[*i + 1];
        operators[2] = '\0';
        *i += 2;
        type = ft_get_operator_type(operators);
    }
    else
    {
        operators[0] = input[*i];
        operators[1] = '\0';
        (*i)++;
        type = ft_get_operator_type(operators);
    }
    ft_adding_tokens(tokens, type, operators);
}

void   ft_lexing_words(char *input, int *i, t_list **tokens)
{
    int     start;
    char    *quoted;

    if (ft_is_quote(input[*i]))
    {    
        quoted = ft_take_element_between_quotes(input, i);
        ft_adding_tokens(tokens, TOKEN_ARGUMENT, quoted);
        free (quoted);
        return ;
    }
    start = *i;
    while (input[*i] && !ft_isspace(input[*i]) && !ft_isallsimbols(input[*i]))
        (*i)++;
    ft_adding_tokens(tokens, TOKEN_ARGUMENT, ft_strndup(&input[start], *i - start));
}
