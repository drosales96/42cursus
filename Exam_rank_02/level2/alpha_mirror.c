/*REFLEJA LA MISMA POSICION DE LA LETRA DEL ABECEDAERIO PERO DESDE EL FINAL. EJ: A - Z*/

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
                av[1][i] = 122 - av[1][i] + 'a';
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                av[1][i] = 90 - av[1][i] + 'A';
            write(1, &av[1][i++], 1);   
        }
    }
    write(1, "\n", 1);
    return (0);
}