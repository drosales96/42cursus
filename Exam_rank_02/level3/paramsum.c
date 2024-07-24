/*SUMA TODOS LOS ARGUMENTOS QUE ENTRAN POR STDIN*/

#include <unistd.h>

void    decimals(int n)
{
    if (n > 9)
        decimals(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int main(int ac, char **av)
{
    (void)av;
    decimals(ac - 1); //-1 PARA NO CONTAR A.OUT
    write(1, "\n", 1);
    return (0);
}