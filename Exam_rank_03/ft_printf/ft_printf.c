#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void    ft_putstr(char *str, int *len)
{
    if (!str)
        str = "(null)";
    while (*str)
        *len += write(1, str++, 1);
}

void ft_putnum(long long nbr, int base,  int *len)
{
    char    *hex;

    hex = "0123456789abcdef";
    if (nbr < 0)
    {
        nbr *= -1;
        *len += write(1, "-", 1);
    }
    if (nbr >= base)
        ft_putnum((nbr/base), base, len);
    *len += write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
    int     len;
    va_list ptr;

    len = 0;
    va_start(ptr, format);
    while (*format)
    {
        if ((*format == '%') && *(format + 1))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(ptr, char *), &len);
            else if (*format == 'd' || *format == 'i')
                ft_putnum((long long int)va_arg(ptr, int), 10, &len);
            else if (*format == 'x')
                ft_putnum((long long int)va_arg(ptr, unsigned int), 16, &len);
        }
        else
            len += write(1, format, 1);
        format ++;
    }
    return (va_end(ptr), len);
}
