/*FUNCION PARA REALIZAR LA COPIA DE UN STRING EN UNA DIRECCION DE MEMORIA (DST)*/
/*PROTOTIPO DADO POR EL EJERCICIO*/

#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main(void)
{
    char    src[] = "Hola mundo";
    char    dst[] = "";
    int     res;

    ft_strcpy(dst, src);
    printf("%s", dst);
    return (0);
}