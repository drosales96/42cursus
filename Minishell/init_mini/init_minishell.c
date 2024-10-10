/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:40:24 by marigome          #+#    #+#             */
/*   Updated: 2024/10/10 15:54:41 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_mini  *init_mini(char **env)
{
    t_mini *mini;

    mini = (t_mini *)malloc(sizeof(t_mini));
    if (!mini)
        return (NULL);

    // Inicializar la lista de variables de entorno
    mini->list_env = init_env_list(env);
    if (!mini->list_env)
    {
        free(mini);
        return (NULL);  // Manejo de errores si la inicialización del entorno falla
    }

    // Inicializar otras variables de t_mini
    mini->env = env;  // Guardamos el array envp por si lo necesitamos más tarde
    mini->stdin = dup(STDIN_FILENO);  // Duplicar stdin para poder restaurarlo después
    mini->stdout = dup(STDOUT_FILENO); // Duplicar stdout para poder restaurarlo después
    mini->line = NULL; // La línea de comandos se inicializará más tarde
    mini->tokens = NULL;
    mini->exit = 0;
    return (mini);
}