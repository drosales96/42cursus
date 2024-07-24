/*ESTE PROGRAMA COGE EL ARG1 Y TODO LO QUE SEA MINUSCULA PASA A MAYUSCULA*/

 #include <unistd.h>

 void   ft_putchar(char c)
 {
    write(1, &c, 1);
 }
 
 int    ft_isspace(int c)
 {
    if (c <= 32)
        return (1);
    return (0);
 }

 void   rstr_capitalizer(char *s)
 {
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        if ((s[i] >= 'a' && s[i] <= 'z') && ft_isspace(s[i + 1]))
            s[i] -= 32;
        ft_putchar(s[i++]);
    }     
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac <= 1)
        ft_putchar('\n');
    else
    {
        while (i < ac)
        {
            rstr_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}