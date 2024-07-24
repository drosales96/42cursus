/*HACE LO MISMO QUE FT_RANGE PERO DEL REVERSO*/

#include <stdlib.h> //FOR MALLOC

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
    int *range = (int *)malloc(sizeof(int) * len);

    if (!range)
        return (NULL);
    while (i < len)
    {
        if (end < start)
            range[i] = end++;
        else
            range[i] = end--;
        i++;
    }
    return (range);
}