/*HAY QUE REPLICAR LA FUNCION SPLIT, Y ESTA FORMA ES BASTANTE ABREVIADA Y FACIL DE USAR*/

#include <unistd.h>
#include <stdlib.h> // FOR MALLOC
#include <stdio.h> // FOR PRINTF

char    *ft_strncpy(char *dst, char *src, int len)
{
    int i = 0;

    while (i < len && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return(dst);
}

int ft_isspace(int c)
{
    if (c == 32 || c == 9 || c == 10)
        return (1);
    return (0);
}

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int wordlen = 0;

    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        if (str[i])
            wordlen++;
        while (str[i] && !ft_isspace(str[i]))
            i++;
    }
    char    **res = (char **)malloc(sizeof(char *) * wordlen + 1);
    i = 0;
    /*if (!res)
        return(NULL);*/
    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        j = i;
        while (str[i] && !ft_isspace(str[i]))
            i++;
        if (i > j)
        {
            res[k] = (char *)malloc(sizeof(char) * (i - j) + 1);
            /*if (!res)
                return (NULL);*/
            ft_strncpy(res[k++], &str[j] , i - j);
        }
    }
    res[k] = NULL;
    return (res);
}

/*int main(void)
{
    char *str = "Hola mi login es drosales y estudio en 42 Telefónica";
    char **result = ft_split(str);

    if (result)
    {
        int i = 0;
        while (result[i])
        {
            printf("result[%d]: %s\n", i, result[i]);
            i++;
        }
        printf("Número de strings: %d\n", i);

        
        for (int j = 0; j < i; j++)
            free(result[j]);
        free(result);
    }
    return (0);
}
*/