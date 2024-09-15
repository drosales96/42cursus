#include <unistd.h>
#include <stdarg.h>

static int ft_putstr(char *str, int i)
{
	if (!str)
		return (ft_putstr("(null)"));
	if (!str[i])
		return (i);	
	while  (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_putstr(str, i + 1));
}

static int ft_putnbr(long num, int base)
{
	char *b = "0123456789abcdef";
	if (num < 0 && base == 10)
		return (write(1, "-", 1) + ft_putnbr(num * -1, base));
	if (num > 0 && base == 10)
		return (ft_putnbr((unsigned int)num, base));
	if (num/base == 0)
		return (write(1, &b[num%base], 1));
	return (ft_putnbr(num/base, base) + ft_putnbr(num%base. base));
}

static int type(char *s, va_list args, int i, int n)
{
	if (!s[i])
		return (n);
	if (s[i] == '%' && s[i + 1] == 's')
		return (type(s, args, i + 2, n + ft_putstr(va_arg(args, char *), 0)));
	else if (s[i] == '%' && s[i + 1] == 'd')
		return (type(s, args, i + 2, n + ft_putnbr(va_arg(args, int), 10)));
	else if (s[i] == '%' && s[i + 1] == 'i')
		return (type(s, args, i + 2, n + ft_putnbr(va_arg(args, int), 10)));
	else if (s[i] == '%' && s[i + 1] == 'x')
		return (type(s, args, i + 2, n + ft_putnbr(va_arg(args, int), 16)));
	write(1, &s[i], 1);
	return (type(s, args, i + 1, n + 1));
}

int	ft_printf(char *s, ...)
{
	va_list args;
	return (va_start(args, s), va_end(args), type(s, args, 0, 0));
}
