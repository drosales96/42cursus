/*PROGRAMA CON EL QUE CONVERTIREMOS UN NUMERO DE BASE 10 EN
UN HEXADECIMAL (MINUSCULA)*/

#include <unistd.h>

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

void print_hex(int nb)
{
    if (nb > 16)
        print_hex(nb / 16);
    write(1, &"0123456789abcdef"[nb % 16], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        print_hex(ft_atoi(av[1]));
    }
    write(1, "\n", 1);
    return (0);
}