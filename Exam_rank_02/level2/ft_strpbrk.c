/*RÉPLICA DE LA FUNCION STRPBRK*/

#include <stdio.h> //FOR PRINTF
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j;

    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

/*int main(void)
{
    char    *s1 = "Hello world";
    char    *s2 = "buenas wtardes";

    printf("%s",ft_strpbrk(s1, s2));
    return (0);
}*/