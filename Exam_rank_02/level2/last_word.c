/*DEBES IMPRIMIR LA ULTIMA PALABRA DEL ARGUMENTO 1*/

#include <unistd.h>

int ft_isspace(int c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
            i++;
        while (i >= 0 && (ft_isspace(av[1][i])))
            i--;
        int end = i;
        while (i >= 0 && (!ft_isspace(av[1][i])))
            i--;
        i++;
        while (i <= end)
        {
            write(1, &av[1][i++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}