/*PROGRAMA CON EL QUE PASANDOLE DOS ARGUMENTOS NUMERICOS OBTIENES
EL MAXIMO COMUN DIVISOR*/

#include <unistd.h>
#include <stdio.h> //FOR PRINTF

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
        sign *= -1;
    while (str[i] == '-' || str[i] == '+')
        i++;
    while ((str[i] >= '0' && str[i] <= '9') && str[i])
    {
        res = (res * 10) + str[i] - 48;
        i++;
    }
    return (res * sign);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int n1 = ft_atoi(av[1]);
        int n2 = ft_atoi(av[2]);

        if (n1 > 0 && n2 > 0)
        {
            while (n1 != n2)
            {
                if (n1 > n2)
                    n1 = n1 - n2;
                else
                    n2 = n2 - n1;
            }
            printf("%d", n1);
        }
    }
    printf("\n");
    return (0);
}