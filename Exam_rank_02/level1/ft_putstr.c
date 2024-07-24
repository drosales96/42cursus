/*IMPRIMIR EN PANTALLA UN STRING*/
/*PROTOTIPO DADO POR EJERCICIO*/

#include <unistd.h>

void	ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
        write(1, &str[i++], 1);
}

/*int main()
{
    char    s1[]= "HOLA MUNDO";

    ft_putstr(s1);
    return (0);
}*/