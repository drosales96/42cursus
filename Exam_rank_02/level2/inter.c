/*INTER BUSCAR LAS COINCIDENCIAS DE LOS CHAR DEL PRIMER ARGUMENTO, 
EN EL SEGUNDO ARGUMENTO Y RETORNA EL STRING QUE FORME EN BASE A LAS
COINCIDENCIAS*/

#include <unistd.h>

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int main(int ac, char **av)
{
    int i = 0;
    int j;
    int lookascii[256] = {};

    if (ac == 3)
    {
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[1][i] == av[2][j] && !lookascii[(int)av[2][j]])
                {    
                    lookascii[(int)av[2][j]] = 1;
                    ft_putchar(av[2][j]);
                }
                j++;
            }
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}
