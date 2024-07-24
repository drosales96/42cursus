/*RECIBE UN NUMERO Y TE PROPORCIONA LA SUMA DE NUMEROS PRIMOS
QUE HAY POR DEBAJO DE EL*/

#include <unistd.h>

void    decimals(int nb)
{
    if (nb > 9)
        decimals(nb / 10);
    write(1, &"0123456789"[nb % 10], 1);
}

int ft_isprime(int n)
{
    if (n <= 1)
        return (0);
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return(0);
        i++;
    }
    return (1);
}

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
    if (ac == 2)
    {
        int num = ft_atoi(av[1]);
        int sum = 0;

        while (num > 0)
        {
            if (ft_isprime(num))
                sum += num;
            num--;
        }
        decimals(sum);
    }
    if (ac != 2)
        decimals (0);
    write(1, "\n", 1);
    return (0);
}