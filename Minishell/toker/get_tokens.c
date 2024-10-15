/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:52:09 by marigome          #+#    #+#             */
/*   Updated: 2024/10/11 18:30:26 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Esta funcion nos sirve para darle tamaño a token->str si encontramos comillas*/
int token_size(char *line, int *index)
{
    int i;
    char    c;
    int     size;

    i = 0;
    c = ' ';
    size = 0;
    while (line[*index + i] && (line[*index + i] != ' ' || c != ' '))
    {
        if (c == ' ' && (line[*index + i] == '\'' || line[*index + i] == '\"' ))
        {
            c = line[*index + i]; // Si encontramos comillas c = "
            i++;
        }
        else if (c != ' ' && line[*index + i] == c) // Si encontramos la comilla de cierre
        {
            size += 2; // Para sumarle el tamaño de ambas comillas
            c = ' ';
            i++;
        }
        else 
            i++;
    }
    return (i - size + 1);
}

Token   *read_tokens(char   *line, int *index)
{
    Token   *token;
    int     i;
    char    c;

    i = 0;
    c = ' ';
    token = malloc(sizeof(Token));
    if (!token)
        return (NULL);
    token->token_value = malloc(sizeof(char) * token_size(line, &i));
    if (!token->token_value)
        return (NULL);
    while (line[*index] && (line[*index] != ' ' || c != ' '))
    {
        if ((line[*index] == 34 || line[*index] == 39) && c == ' ')
            c = line[*index];
        if ((line[*index]) == c && c != ' ')
        {
            c = ' ';
            (*index)++;
        }
        else
            token->token_value[i++] = line[(*index)++];
    }
    token->token_value[i] = '\0';
    return (token);
}

void ft_update_type_tokens(Token *token)
{
    if (ft_strcmp(token->token_value, "") == 0)
        token->token_type = TOKEN_EMPTY;
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
        token->prev->token_type == TOKEN_REDIRECT_IN || 
        token->prev->token_type == TOKEN_REDIRECT_OUT || 
        token->prev->token_type == TOKEN_REDIRECT_APPEND || 
        token->prev->token_type == TOKEN_REDIRECT_HEREDOC))
        token->token_type = TOKEN_ARGUMENT;
    else if (token->prev == NULL || token->prev->token_type == TOKEN_PIPE)
        token->token_type = TOKEN_COMMAND;
    else if (token->prev->token_type == TOKEN_COMMAND)
        token->token_type = TOKEN_ARGUMENT;
    else
        token->token_type = TOKEN_ARGUMENT;
}

Token   *get_tokens(char *line)
{
    Token   *token;
    Token   *prev;
    int     i;

    token = NULL;
    prev = NULL;
    i = 0;

    ft_pass_spaces(line, &i);
    while (line[i])
    {
        token = read_tokens(line, &i);
        token->prev = token;
        if (prev)
            prev->next = token;
        token->prev = prev;
        prev = token;
        ft_update_type_tokens(token);
        ft_pass_spaces(line, &i);
    }
    if (token)
        token->next = NULL;
    while (token && token->prev)
        token = token->prev;
    return (token);
}

void print_tokens(Token *tokens)
{
    Token *current = tokens;
    while (current != NULL) 
    {
        ft_printf("####Tokenizing in progress...####\n");
        ft_printf("Token: [%s]\n Type: [%d]\n\n", current->token_value, current->token_type);
        current = current->next;
    }
}

t_ast *ft_parse(t_mini *minishell)
{
    t_ast *ast; // Debe ser un puntero a t_ast

    sig_init(); 
    minishell->line = readline("minishell: ");
    if (!minishell->line)
    {
        minishell->exit = 1;
        ft_putendl_fd("exit", STDERR_FILENO);
        return NULL; // Retorna NULL si hay un error
    }
    if (*minishell->line)
        add_history(minishell->line);

    if (ft_checker_quotes_unclosed(minishell))
    {
        free(minishell->line);
        return NULL; // Retorna NULL si hay un error
    }

    minishell->tokens = get_tokens(minishell->line);
    print_tokens(minishell->tokens);
    ast = ft_making_ast(minishell->tokens);

    if (ast)
        ft_print_ast(ast);

    free(minishell->line);
    return ast; // Asegúrate de retornar un puntero a t_ast
}
