/*RETORNA UN STRING DEL REVES PERO SIN USAR WRITE*/

#include <stdio.h>

char    *ft_strrev(char *str)
{
    int     i = 0;
    int     len = 0;
    char    temp;

    while (str[len])
        len++;
    while (i < len - 1) 
    {
        temp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = temp;
        i++;
        len--;
    }
    return (str);
}

int main(void)
{
    char    str[] = "Hello world";
    char    str2[] = "olleH";

    printf("%s\n", ft_strrev(str));
    printf("%s\n", ft_strrev(str2));
    return (0);
}