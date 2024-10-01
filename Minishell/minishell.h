/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:21:18 by drosales          #+#    #+#             */
/*   Updated: 2024/10/01 13:30:03 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdint.h>

/* 42 LIBS */

# include "Libft/libft.h"
# include "Printf/ft_printf.h"

/* DATA STRUCTS */

typedef enum
{
    TOKEN_COMMAND,              /* Comando a ejecutar */
    TOKEN_ARGUMENT,             /* Argumento */
    TOKEN_PIPE,                 /* Pipe " | " */
    TOKEN_REDIRECT_OUT,         /* Redirección salida > */
    TOKEN_REDIRECT_IN,          /* Redirección de entrada < */
    TOKEN_REDIRECT_APPEND,      /* Redirección de salida en modo append >> */
    TOKEN_FILE,                 /* Archivos */
    TOKEN_UNKNOWN               /* Elemento no reconocido */
}Token_type;

typedef struct
{
    Token_type  type;           /* Para saber el tipo de token */
    char        *token_value;   /* Valor del token */
}Token;

typedef struct s_list           /* Estructura para lista enlazada */
{
    Token           token;      /* Estructura referente a tokens */
    struct s_list   *next;      /* Puntero al siguiente nodo */
}t_list;

/* FUNCTIONS */

t_list      *ft_lexer(char  *input);
t_list      *ft_new_node_tokens(Token_type type, const char *value);
Token       ft_adding_tokens(t_list **head_list, Token_type type, const char *value);
void        ft_print_tokens(t_list **head_list);
char        *ft_take_element_between_quotes(char *input, int *i);
Token_type  ft_get_operator_type(char *operator);
void        ft_lexing_words(char *input, int *i, t_list **tokens);
void        *ft_lexing_operators(char *input, int *i, t_list **tokens);
int         ft_strnlen(const char *str, size_t maxlen);
char	    *ft_strndup(const char *str, size_t n);
int         ft_isspace(int c);
int         ft_is_quote(int c);
int         ft_isallsimbols(int c);
int         ft_strncmp(char *s1, char *s2);

#endif