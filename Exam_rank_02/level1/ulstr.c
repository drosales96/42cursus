/*CAMBIA TODAS LAS MINUSCULAS A MAYUSCULAS Y AL REVES*/

#include <unistd.h> // FOR WRITE

int low(int c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int upper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}
int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
        {
            if (low(av[1][i]))
                av[1][i] -= 32;
            else if (upper(av[1][i]))
                av[1][i] += 32;
            write(1, &av[1][i++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
