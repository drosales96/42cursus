/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:01:18 by drosales          #+#    #+#             */
/*   Updated: 2024/10/11 19:45:59 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_signal g_signals;

int main(int ac, char **argv, char **env) 
{
    (void)ac;
    (void)argv;
    t_mini *minishell;
    //t_env *current; // Esto es para que lo printee (Luego lo borramos)
    init_signals(&g_signals);
    sig_init();
    ft_printf("Welcome to marigome a drosales Minishell!\n\n");

    minishell = init_mini(env);
    if (!minishell)
        return (EXIT_FAILURE);
    
    /*current = minishell->list_env;
    while (current) // Bucle para que lo muestre por pantalla (Borrar)
    {
        printf("Variable: %s=%s\n", current->key, current->value);
        current = current->next;
    }*/
    
    while (!g_signals.exit) 
    {
        t_ast *cmd_ast = ft_parse(minishell); // Asegúrate de que cmd_ast es un puntero a t_ast.

        if (cmd_ast) {
            ft_is_builtin(cmd_ast); // Pasa el nodo AST a la función de builtins.
        }
    }
    
    clear_history();
    return (0);
}
