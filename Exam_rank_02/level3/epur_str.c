/*COGE EL ARG1 Y CUALQUIER ESPACIO QUE HAYA LO CONVIERTE EN
UN SOLO ESPACIO (CANTIDAD)*/

#include <unistd.h>

/*void    ft_putchar(char c)
{
    write(1, &c, 1);
}*/

int ft_isspace(int c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        int space = 0;
        while (av[1][i])
        {
            if (ft_isspace(av[1][i]))
                space = 1;
            if (!ft_isspace(av[1][i]))
            {
                if (space)
                    write(1, " ", 1);
                space = 0;
                write(1, &av[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}