/*EJERCICIO QUE RETORNA EL NUMERO MAXIMO DENTRO DE UN ARRAY DE NUMEROS*/

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i = 0;
    int result;

    if (len == 0)
        return (0);
    result = tab[i];
    while (i < len)
    {
        if (result < tab[i])
            result = tab[i];
        i++;
    }
    return (result);
}

/*int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int length = sizeof(array) / sizeof(array[0]);

    int max_value = max(array, length);

    printf("El valor máximo del array es: %d\n", max_value);
    return (0);
}*/