/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:01:18 by drosales          #+#    #+#             */
/*   Updated: 2024/10/10 19:15:22 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*static void ft_print_ast(t_ast *node)
{
    if (!node)
        return;

    if (node->type == TOKEN_COMMAND)
        printf("Comando: %s\n", node->value);
    else if (node->type == TOKEN_ARGUMENT)
        printf("Argumento: %s\n", node->value);
    else if (node->type == TOKEN_OPERATOR)
        printf("Operador: %s\n", node->value);
    else if (node->type == TOKEN_PATH)
        printf("Archivo/Path: %s\n", node->value);
    if (node->left)
        printf("  └ Left: ");
    ft_print_ast(node->left);
    if (node->right)
        printf("  └ Right: ");
    ft_print_ast(node->right);
}*/

int main(int ac, char **argv, char **env) 
{
    (void)ac;
    (void)argv;
    t_mini  *minishell;
    //token_list *tokens;
    t_env   *current; // Esto es para que lo printee (Luego lo borramos)
    //t_ast   *cmd_ast;
    ft_printf("Welcome to marigome a drosales Minishell!\n\n");
    minishell = init_mini(env);
    if (!minishell)
        return (EXIT_FAILURE);
    current = minishell->list_env;
    while (current) // Bucle para que lo muestre por pantalla (Borrar)
    {
        printf("Variable: %s=%s\n", current->key, current->value);
        current = current->next;
    }
    while (minishell->exit == 0) 
    {
        ft_parse(minishell);
        //free(minishell->line);
    }
    clear_history();
    return (0);
}