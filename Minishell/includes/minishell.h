/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:21:18 by drosales          #+#    #+#             */
/*   Updated: 2024/10/10 18:42:27 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include<stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdint.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* DATA STRUCTS */

typedef enum
{
    TOKEN_EMPTY,               	/* "" */
	TOKEN_REDIRECT_IN,			/* < */
	TOKEN_REDIRECT_OUT,			/* > */
	TOKEN_REDIRECT_APPEND,		/* >> */
	TOKEN_REDIRECT_HEREDOC,		/* << */
	TOKEN_COMMAND,              /* Comando a ejecutar */
    TOKEN_ARGUMENT,             /* Argumento */
    TOKEN_PIPE,             	/* Operadores */
    TOKEN_PATH               	/* Path */
}Token_type;

typedef struct s_Token
{
    Token_type  	    token_type;      /* Para saber el tipo de token */
    char        	    *token_value;   /* Valor del token */
	struct s_Token      *next;      /* Puntero al siguiente nodo */
    struct s_Token      *prev;
}Token;

typedef struct s_env            /* Estructura para variables de entorno*/
{
    char    *key;
    char    *value;
    struct s_env    *next;
}   t_env;

typedef struct s_mini           /* Estructura programa minishell*/
{
    char    **env;              /* Variables de entorno */
    t_env   *list_env;          /* Puntero a mi lista de variables de entorno */    
    int     stdin;              /* Entrada en estandar */
    int     stdout;             /* Salida estándar */    
    char    *line;              /* Línea */
    Token   *tokens;             /* Puntero a mi lista de tokens */
	int		exit;
}   t_mini;

typedef struct s_signal
{
    pid_t   pid;
    int     sigint;
	int		sigquit;
	int		exit;
}   t_signal;

/* AST STRUCT */

typedef struct s_ast
{
    Token_type      type;       // TYPE OF NODE (TOKEN_ARGUMENT...)
    char            *value;     // VALUE OF NODE (PIPE = '|'...)
    struct s_ast    *right;     // RIGHT NODE
    struct s_ast    *left;      // LEFT NODE
}   t_ast;

/** FUNCTIONS **/

/* Init minishell */

t_mini  *init_mini(char **env);

/* Init environment */

t_env  *init_env_list(char **envp);

/* Signals */
void    sig_init(void);
void    init_signals(t_signal *signals);

/* Lexer y tokenizer */

/*Token      *ft_lexer(char  *input);
Token      *ft_new_node_tokens(Token_type type, const char *value);
Token           ft_adding_tokens(Token **head_list, const char *value);
char            *ft_take_element_between_quotes(char *input, int *i);
Token_type      ft_get_operator_type(char *operator);
void            ft_lexing_words(char *input, int *i, Token **tokens);
void            ft_lexing_operators(char *input, int *i, Token **tokens);
void            ft_lexing_double_operators(const char *input, int *i, Token **tokens);
int             ft_strnlen(const char *str, size_t maxlen);
char	        *ft_strndup(const char *str, size_t n);
int             ft_isspace(int c);
int             ft_is_quote(int c);
int             ft_isallsimbols(int c);
int             ft_strcmp(const char *s1, const char *s2);
int             ft_is_operator(const char *value);
int             ft_is_command(const char *value);
int             ft_is_path(const char *value);
Token_type      ft_type_of_tokens(char *value); */

/* Parsing AST */
/*
t_ast           *ft_parsing_cmd(Token *tokens);
t_ast           *ft_parsing_operator(Token *tokens, t_ast *left_cmd);
t_ast           *ft_parsing_path(Token *tokens);
t_ast           *ft_parsing_args(Token *tokens);
t_ast           *ft_ast_new_node(Token_type type, char *value);
t_ast           *ft_making_ast(Token *tokens); */

/* PARSE BEFORE TOKEN */
int 	ft_check_operators(char *line, int index);
int 	ft_checker_quotes_unclosed(t_mini *minishell);
int 	ft_checker_quotes(char  *line, int index);
void    ft_pass_spaces(char *line, int *i);
void    ft_update_type_tokens(Token *token);
int 	token_size(char *line, int *index);
Token   *read_tokens(char   *line, int *index);
Token   *get_tokens(char *line);
void    ft_parse(t_mini *minishell);
int		ft_strcmp(const char *s1, const char *s2);
void    print_tokens(Token *tokens);

#endif