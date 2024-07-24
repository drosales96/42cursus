/*EJERCICIO PARA IMPRIMIR NUMEROS DEL 1 AL 100 Y ADEMAS SUSTITUIR
LOS QUE SON MULTIPLOS DE 3 POR 'fizz', LOS QUE LO SON DE 5 POR 'buzz'
Y LOS QUE LO SON DE AMBOS POR 'fizzbuzz'*/

#include <unistd.h>

void    decimals(int n)
{
    if (n > 9)
        decimals(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int main(void)
{
    int nb = 1;

    while (nb <= 100)
    {
        if (nb % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if (nb % 3 == 0)
            write(1, "fizz", 4);
        else if (nb % 5 == 0)
            write(1, "buzz", 4);
        else
            decimals(nb);
        nb++;
        write(1, "\n", 1);
    }
    return (0);
}