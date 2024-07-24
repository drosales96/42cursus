/*VERIFICA SI EL NUMERO DADO ES POTENCIA DE 2*/

#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    return (n & (n - 1)) == 0;
}

/*int main(void)
{
    unsigned int nb = 16;

    int res = is_power_of_2(nb);
    printf("%d", res);
    return (0);
}*/