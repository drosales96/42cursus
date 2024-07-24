/*RÉPLICA DE LA FUNCION STRCSPN (RETORNA LOS CARACTERES (NÚMERO) EN 'S' QUE NO COMPARTE CON REJECT
ANTES DE ENCONTRARSE UNA COINCIDENCIA)*/

    #include <stdlib.h> //FOR SIZE_T
    #include <stdio.h> //FOR PRINTF

    size_t	ft_strcspn(const char *s, const char *reject)
    {
        int i = 0;
        int j;

        while (s[i])
        {
            j = 0;
            while (reject[j])
            {
                if (s[i] == reject[j])
                    return (i);
                j++;
            }
            i++;
        }
        return (i);
    }

    /*int main(void)
    {
        char    *s = "Hello World";
        char    *reject = "aeiou";

        int res = ft_strcspn(s, reject);
        printf("%d\n", res);
        return (0);
    }*/