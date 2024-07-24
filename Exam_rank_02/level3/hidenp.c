/*ESTE PROGRAMA BUSCA LA COINCIDENCIA DEL ARG1 EN ARG2 EN EL MISMO ORDEN QUE TIENE ARG, SI ESTA EN
ARG 2 ENTONCES RETORNA 1, SINO 0 */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;

    if (ac == 3)
    {
        while (av[2][j] && av[1][i])
        {
            if (av[2][j] == av[1][i])
                i++;
            j++;
        }
        if (av[1][i] == 0)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}