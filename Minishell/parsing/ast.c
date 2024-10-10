/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:07 by marigome          #+#    #+#             */
/*   Updated: 2024/10/10 15:25:13 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*t_ast *ft_making_ast(Token *tokens)
{
    t_ast  *ast;
    t_ast   *current_ast;

    current_ast = NULL;
    ast = NULL;
    if (!tokens)
        ft_printf("There are no tokens for now!\n");
    while (tokens != NULL)
    {
        if (tokens->token_type == TOKEN_COMMAND)
        {    
            current_ast = ft_parsing_cmd(tokens);
            if (!ast)
                ast = current_ast;
            else
                ast->right = current_ast;
            tokens = tokens->next;
        }
        else if (tokens->token.token_type == TOKEN_ARGUMENT)
        {    
            ast->right = ft_parsing_args(tokens);
            tokens = tokens->next;
        }
        else if (tokens->token.token_type == TOKEN_OPERATOR)
        {    
            ast = ft_parsing_operator(tokens, ast);
            tokens = tokens->next;
        }
        else if (tokens->token.token_type == TOKEN_PATH)
        {    
            ast->right = ft_parsing_path(tokens);
            tokens = tokens->next;
        }
        else
            tokens = tokens->next;
    }
    return (ast);
}

/* 

¿Qué siginifican las siglas 'AST'? :

 El Árbol de sintaxis abstracta es una estructura de datos usada extensamente en compiladores, debido a su propiedad de representar la estructura del código de un programa. Un AST es usualmente el resultado del analizador sintáctico en la fase de un compilador.
 
 */


/*t_ast   *ft_ast_new_node(Token_type type, char *value)
{
    t_ast   *node;

    node = malloc(sizeof(t_ast));
    if (!node)
    {
        ft_printf("Allocation for AST is no being posible!...\n");
        return (NULL);
    }
    node->type = type;
    node->value = ft_strdup(value);
    if (node->value == NULL)
        return (NULL);
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/*
    POSIBLES ERRORES

    Pipe sin comando previo:
        | grep "error"
    
        Errores:
        GPT:Error de sintaxis.
        Bash: error sintáctico cerca del elemento inesperado `|'

    Pipe sin comando siguiente:
        cat file.txt |
    
        Errores:
        GPT: Error de sintaxis.
        Bash: sigue esperando hasta que le metas comando
    hasta que le metes otro comando.

    Dos pipes consecutivos:
        cat file.txt || grep "error"

        Errores:
        bash:
        1º Si no existe el archivo .txt te da error "No existe el archivo" y se queda pillado
        2º Si existe el archivo: En bash no te da error con dos || (OJO)

        GPT: Error de sintaxis.
    Redirección sin archivo de entrada:
        grep "error" <

        Errores:
        bash: error sintáctico cerca del elemento inesperado `newline'
        GPT: Error de sintaxis.

    Redirección sin archivo de salida:
        grep "error" >

        Errores:
        Bash: error sintáctico cerca del elemento inesperado `newline'
        GPT: error de sintaxis.

    Dos redirecciones consecutivas sin archivo:
        cat file.txt > < input.txt

        Errores:
        Bash: error sintáctico cerca del elemento inesperado `<'
        GPT: Error de sintaxis.

    Redirección en una posición incorrecta:
        > grep "error" file.txt

        Errores:
        Bash: Orden «error» no encontrada. Quizá quiso decir:
        la orden «perror» del paquete deb «mysql-server-core-8.0 (8.0.39-0ubuntu0.24.04.2)»
        la orden «perror» del paquete deb «mariadb-client (1:10.11.8-0ubuntu0.24.04.1)»
        GPT: Error de sintaxis

    Comando vacío:
        (solo presionar Enter sin escribir nada)

        Errores:
        Bash: Sigue sacando líneas vacías.
        GPT: No sucede nada o se imprime un nuevo prompt. (Coinciden)

    Redirecciones repetidas de salida sin comando:
        grep "error" > > output.txt

        Errores:
        Bash: error sintáctico cerca del elemento inesperado `>'
        GPT: Error de sintaxis

    Uso incorrecto de operadores no soportados:
        ls && pwd

        Errores:
        Bash: (Sí hace porque lo tiene, el nuestro NO)
        GPT: Error de comando no soportado.

    Uso de elementos no reconocidos:
        mycustomcommand "error"

        Errores:
        Bash: mycustomcommand: no se encontró la orden
        GPT: Error de "comando no encontrado"

*/