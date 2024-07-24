/*RÉPLICA DE LA FUNCION STRCMP*/

#include <unistd.h>
#include <stdio.h> // FOR PRINTF

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}

/*int main(void)
{
    char    *s1 = "Hello World";
    char    *s2 = "Hello Diego";

    int res = ft_strcmp(s1, s2);
    printf("La diferencia entre ambos caracteres es de: %d\n", res);
    return (0);
}*/