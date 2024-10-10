/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:09:11 by marigome          #+#    #+#             */
/*   Updated: 2024/10/10 19:14:28 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// QUOTES TOOLS //
int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}


/* Vamos a ver si tenemos comillas y si están cerradas
o están abiertas */
int ft_checker_quotes(char  *line, int index)
{
    int flag;
    int i;

    flag = 0;
    i = 0;
    while (line[i] && i < index)
    {
        if (line[i] == '\'' && flag == 0)
            flag = 1;
        else if (line[i] == '\"' && flag == 0)
            flag = 2;
        else if (line[i] == '\'' && flag == 1)
            flag = 0;
        else if (line[i] == '\"' && flag == 2)
            flag = 0;
        i++;
    }
    return (flag);
}


/* Propuesta si decidimos mostrar mensaje de error
   Si quotes no cerradas */

   /* ERRORES */
    /*Valor entero 	Nombre
0 	Entrada estándar (stdin)
1 	Salida estándar  (stdout)
2 	Error estándar   (stderr)*/ 

int ft_checker_quotes_unclosed(t_mini *minishell)
{
    if (ft_checker_quotes(minishell->line, ft_strlen(minishell->line)) != 0)
    {
        ft_putendl_fd("Syntax error quotes unclosed", STDERR);
        free(minishell->line);
        return (1);
    }
    return (0);
}

int ft_check_operators(char *line, int index)
{
    if (ft_strchr("<>|", line[index]) && ft_checker_quotes(line, index) == 0)
        return (1);
    return (0);
}

void    ft_pass_spaces(char *line, int *i)
{
    while (line[*i] == 32 || (line[*i] >= 9 && line[*i] <= 13))
        (*i)++;
}







