/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:01:18 by drosales          #+#    #+#             */
/*   Updated: 2024/10/01 13:02:27 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char input[1024];
    t_list *tokens;

    printf("Introduce un comando: ");
    fgets(input, sizeof(input), stdin);

    // Eliminamos el salto de línea al final de la entrada
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Procesamos la entrada con el lexer
    tokens = ft_lexer(input);

    // Imprimimos los tokens generados
    printf("Tokens generados:\n");
    ft_print_tokens(&tokens);

    // FUTURA FUNCION PARA LIBERAR TOKENS

    return (0);
}