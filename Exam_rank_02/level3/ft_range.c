/*ES UNA FUNCION MATEMATICA QUE AL PASARLE POR ARGUMENTO UN INICIO Y FINAL DE UN SECUENCIA DE
NUMEROS, TE SACA POR PANTALLA TODOS LOS QUE INTERVIENEN. POR EJEMPLO (1,10) // OUTPUT: 0, 1, 2, 3...10*/

#include <stdlib.h> //FOR MALLOC

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
    int *range = (int *)malloc(sizeof(int) * len + 1);

    if (!range)
        return (NULL);
    while (i < len)
    {
        if (start < end)
            range[i] = start++;
        else
            range[i] = start--;
        i++;
    }
    return (range);
}
