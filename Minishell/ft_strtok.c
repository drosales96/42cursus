/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:26:12 by drosales          #+#    #+#             */
/*   Updated: 2024/09/26 19:53:53 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}
char *ft_strtok(char *str, const char *delim)
{
    static char *input;
    char        *token_start;

    if (str != NULL) /*SI STR NO ES NULL COMENZAMOS DESDE UNA NUEVA CADENA*/
        input = str;
    if (input == NULL) /*SI NO HAY MAS TOKENS*/
        return (NULL);
    while (*input && ft_strchr(delim, *input)) /*SALTAMOS LOS DELIMITADORES INICIALES*/
        input++;
    if (*input == '\0') /*SI LLEGAMOS AL FINAL DE LA CADENA DESPUES DE LOS DELIMITADORES*/
        return (NULL);
    token_start = input; /*GURDAMOS EL TOKEN*/
    while (*input && !ft_strchr(delim, *input)) /*AVANZAMOS SOBRE EL TOKEN HASTA UN NUEVO DELIMITADORE O HASTA EL FINAL DE LA CADENA*/
        input++;
    if (*input) /*UNA VEZ ENCUENTRE UN DELIMITADOR (CON LA LINEA DE ARRIBA) LO QUE HAREMOS SERÁ REEMPLAZARLO POR UN '\0'*/
    {
        *input = '\0';
        input++;
    }
    return (token_start);
    /* RETORNAMOS EL TOKEN*/
    /*
    DE ESTA MANERA POR EJEMPLO CON "ls -l" (USANDO UN BUCLE) CON LA FUNCION
    FT_STRTOK, SACARIAMOS EN LA PRIMERA VUELTA EL TOKEN "ls\0" Y CONTINUARIAMOS
    GRACIAS AL BUCLE SACANDO CADA TOKEN...
    
    RESULTADO = {"ls\0", "-l\0"}

    Y DESPUÉS YA PODRIAMOS TRABAJAR CON LOS COMANDOS. Y A ESTE PROCESO SE LE
    LLAMA "PARSEAR"
    */
}

int main() 
{
    char str[] = "Hola, este es un ejemplo de tokenización";
    char *token = ft_strtok(str, " ,");

    while (token != NULL) {
        printf("%s\n", token);
        token = ft_strtok(NULL, " ,");  // Continuamos tokenizando la misma cadena
    }

    return 0;
}
