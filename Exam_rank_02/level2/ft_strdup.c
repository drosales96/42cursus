/*REALIZAR UNA COPIA DE UN STR EN UN BUFFER CREADO CON MALLOC*/

#include <stdlib.h> //FOR MALLOC
#include <stdio.h> //FOR PRINTF

char    *ft_strdup(char *src)
{
    int     i = 0;
    int     len = 0;
    char    *buffer;

    while (src[len])
        len++;
    buffer = (char *)malloc(sizeof(char) * len + 1);
    if (!buffer)
        return (NULL);
    while (src[i])
    {
        buffer[i] = src[i];
        i++;
    }
    buffer[i] = '\0';
    return (buffer);
}

/*int main(void)
{
    char    *src = "HOLA 42";

    printf("%s", ft_strdup(src));
    return (0);
}*/