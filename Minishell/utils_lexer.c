/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:53:53 by drosales          #+#    #+#             */
/*   Updated: 2024/10/01 13:04:46 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list  *ft_new_node_tokens(Token_type type, const char *value)
{
    t_list  *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->token.type = type;
    new_node->token.token_value = ft_strdup(value);
    new_node->next = NULL;
    return (new_node);
    /* Con esta función lo que haremos será añadir los tokens como nodos a nuestra lista enlazada */
}

void    ft_print_tokens(t_list **head_list)
{
    t_list  *current;
    /* Esta función la usaremos para imprimir y comprobar los tokens*/
    current = *head_list;
    while (current->next != NULL)
    {
        if (current->token.type == TOKEN_ARGUMENT)
            ft_printf("ARGUMENT : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_COMMAND)
            ft_printf("COMMAND : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_FILE)
            ft_printf("FILE : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_PIPE)
            ft_printf("PIPE : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_REDIRECT_APPEND)
            ft_printf("REDIRECT APPEND : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_REDIRECT_IN)
            ft_printf("REDIRECT IN : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_REDIRECT_OUT)
            ft_printf("REDIRECT OUT : %s\n", current->token.token_value);
        else if (current->token.type == TOKEN_UNKNOWN)
            ft_printf("UNKNOWN ELEMENT : %s\n", current->token.token_value);
        current = current->next;
    }
}

Token    ft_adding_tokens(t_list **head_list, Token_type type, const char *value)
{
    t_list  *new_node;
    t_list  *current;

    new_node = ft_new_node_tokens(type, value);
    if (head_list == NULL) /* Si la lista está vacía el nuevo nodo será el 1º */
    {
        *head_list = new_node;
        return ;
    }
    current = *head_list;
    while (current->next != NULL) /* Si hay elementos recorremos la lista */
        current = current->next;
    current->next = new_node; /* Una vez recorrida entera añadimos el nuevo nodo al final de la lista */
}

Token_type ft_get_operator_type(char *operator)
{
    if (ft_strcmp(operator, ">") == 0)
        return (TOKEN_REDIRECT_OUT);
    else if (ft_strcmp(operator, ">>") == 0)
        return (TOKEN_REDIRECT_APPEND);
    else if (ft_strcmp(operator, "<") == 0)
        return (TOKEN_REDIRECT_IN);
    else if (ft_strcmp(operator, "|") == 0)
        return (TOKEN_PIPE);
    return (TOKEN_UNKNOWN);
}

int ft_isallsimbols(int c)
{
    if (c == '\'' || c == '\"' || c == '<' || c == '>' || c == '|')
        return (1);
    return (0);
}