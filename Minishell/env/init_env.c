/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:43:11 by marigome          #+#    #+#             */
/*   Updated: 2024/10/08 11:18:21 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env   *new_node_env(char *key, char *path)
{
    t_env *new_node;

    new_node = (t_env *)malloc(sizeof(t_env));
    if (!new_node)
        return (NULL);
    new_node->key = strdup(key);
    new_node->value = strdup(path);
    new_node->next = NULL;
    return (new_node);
}

static void    split_env_var(const char *env, char **key, char **path)
{
    int     key_len;
    char    *find_equal;

    find_equal = ft_strchr(env, '=');  // Encuentra el signo "="
    if (find_equal)
    {
        key_len = find_equal - env;  // Longitud de la clave
        *key = ft_substr(env, 0, key_len);  // Extrae la clave (desde el inicio hasta el '=')
        *path = ft_strdup(find_equal + 1);  // Extrae el valor (desde el caracter después del '=')
    }
    else
    {
        *key = ft_strdup(env);  // Si no hay '=', consideramos toda la cadena como clave
        *path = NULL;  // No hay valor
    }
}

t_env  *init_env_list(char **envp)
{
    t_env *head = NULL;
    t_env *current;
    char *key;
    char *value;
    int i;

    i = 0;
    while (envp[i])
    {
        // Dividimos la variable de entorno en clave (key) y valor (path)
        split_env_var(envp[i], &key, &value);
        t_env *new_node = new_node_env(key, value);
        if (!new_node)
            return (NULL);  // Manejo de errores
        // Añadir el nuevo nodo a la lista
        if (!head)  // Si es el primer nodo
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        i++;
        free(key);  // Liberar la memoria temporal de key y path después de usarlo
        if (value)
            free(value);
    }
    return (head);
}