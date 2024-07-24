/*ESCRIBIR LA PRIMERA PALABRA DEL ARGUMENTO 2*/
/*EN ESTE EJERCICIO NO USAR FT_ISSPACE NORMAL, SINO SOLAMENTE CON ASCII 32 Y 9*/

#include <unistd.h>

int ft_isspace(int c)
{
    if (c == 32 || c == 9)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (ft_isspace(av[1][i]))
            i++;
        while (!ft_isspace(av[1][i]) && av[1][i])
            write(1, &av[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}