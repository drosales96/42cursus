/*HAY QUE REPRODUCIR LA FUNCION ITOA DE C*/

#include <unistd.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
    if (nbr == -2147483648)ç
        return ("-2147483648");
    int n = nbr;
    int len = 0;
    if (nbr <= 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    char    *res = (char *)malloc(sizeof(char) * len + 1);
    if (!res)
        return NULL;
    res[len] = '\0';
    if (nbr == 0)
    {
        res[0] = '0';
        return (res);
    }
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr = -nbr;
    }
    while (nbr)
    {
        res[--len] = nbr % 10 + 48;
        nbr/= 10;
    }
    return (res);
}