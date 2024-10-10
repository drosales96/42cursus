/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:22:38 by drosales          #+#    #+#             */
/*   Updated: 2024/10/10 15:17:28 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_lexing_words(char *input, int *i, Token **tokens)
{
    char *quoted;
    int start;

    while (input[*i] == ' ')
        (*i)++;
    if (ft_is_quote(input[*i]))
    {    
        quoted = ft_take_element_between_quotes(input, i);
        ft_adding_tokens(tokens, quoted);
        free(quoted);
        return;
    }
    start = *i;
    while (input[*i] && !ft_is_quote(input[*i]) && !ft_isallsimbols(input[*i]) && input[*i] != ' ')
        (*i)++; 
    if (*i > start)
    {
        char *token = ft_strndup(&input[start], *i - start);
        ft_adding_tokens(tokens, token);
        free(token);
    }
    while (input[*i] == ' ')
        (*i)++;
    if (ft_isallsimbols(input[*i]))
    {
        char symbol[2];
        symbol[0] = input[*i];
        symbol[1] = '\0';
        ft_adding_tokens(tokens, ft_strdup(symbol));
        (*i)++;
    }
}

void  ft_lexing_operators(char *input, int *i, Token **tokens)
{
    char        operators[3];
    

    if ((input[*i] == '<' && input[*i + 1] == '<') || (input[*i] == '>' && input[*i + 1] == '>'))
    {
        operators[0] = input[*i];
        operators[1] = input[*i + 1];
        operators[2] = '\0';
        *i += 2;
    }
    else
    {
        operators[0] = input[*i];
        operators[1] = '\0';
        (*i)++;
    }
    ft_adding_tokens(tokens, operators);
}

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

Token  *ft_lexer(char  *input)
{
    int             i;
    int             start;
    Token      *tokens;

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
        {
            start = i;
            ft_lexing_words(input, &i, &tokens);
        }
        if (i > start && !ft_isspace(input[i]) && !ft_isallsimbols(input[i]))
            ft_lexing_words(input, &i, &tokens);
    }
    ft_printf("%s", tokens);
    return (tokens);
}
