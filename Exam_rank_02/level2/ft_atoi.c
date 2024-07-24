/*RÉPLICA DE LA FUNCION ATOI DE STDLIB*/

/*#include <stdlib.h>
#include <stdio.h>*/

/*LIBRERIAS PARA PROBAR EL MAIN*/

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '-' && str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i])
    {
        res = (res * 10) + str[i] - 48;
        i++;
    }
    return (res * sign);
}

/*int main(void)
{
    char    *str = "--233";
    char    *str2 = "+-+-233";
    char    *str3 = "--155h155xD";
    char    *str4 = "       --+-155f5";

    int res1 = ft_atoi(str);
    int res2 = ft_atoi(str2);
    int res3 = ft_atoi(str3);
    int res4 = ft_atoi(str4);
    
    int real1 = atoi(str);
    int real2 = atoi(str2);
    int real3 = atoi(str3);
    int real4 = atoi(str4);

    printf("---- MY  FT_ATOI ----\n");

    printf("%d\n", res1);
    printf("%d\n", res2);
    printf("%d\n", res3);
    printf("%d\n", res4);

    printf("---- REAL ATOI ----\n");

    printf("%d\n", real1);
    printf("%d\n", real2);
    printf("%d\n", real3);
    printf("%d\n", real4);

    printf("END OF TESTING\n");

}*/