/*ES LO CONTRARIO A RSTR_CAPITALIZER*/

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

 void   str_capitalizer(char *s)
 {
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        if ((s[i] >= 'a' && s[i] <= 'z') && ft_isspace(s[i - 1]))
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
            str_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}