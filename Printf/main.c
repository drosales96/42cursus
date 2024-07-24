
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char	*ptr;

	ptr = "holamundo";
	int	result1;
	int	result2;
	int result3;
	int result4;
	int result5;
	int result6;
	int result7;

	ft_printf("-------Prueba ft_printf-------\n\n");
	result1= ft_printf("Mi nombre es %s, y la primera letra es la %c\n", "Diego", 'D');
	ft_printf("Ha contabilizado %d caracteres\n\n", result1);

	result2 = ft_printf("La dirección de memoria del puntero es %p\n", &ptr);
	ft_printf("Ha contabilizado %d caracteres\n\n", result2);

	result3 = ft_printf("Los números mágicos son %d y %i\n", 4, 2);
	ft_printf("Ha contabilizado %d caracteres\n\n", result3);

	result4 = ft_printf("Un ejemplo de unsigned int sería %u\n", 42);
	ft_printf("Ha contabilizado %d caracteres\n\n", result4);

	result5 = ft_printf("Hexadecimal mayúscula %X y en minúscula %x\n", 0xFF, 0x2A);
	ft_printf("Ha contabilizado %d caracteres\n\n", result5);
	
	result6 = ft_printf("Prueba de %%\n");
	ft_printf("Ha contabilizado %d caracteres\n\n", result6);

	result7 = ft_printf("%c%c%c:Estudiamos en %s, donde estamos viendo números hexadecimales en minúsculas %x y en mayúsculas %X, aunque no nos podemos olvidar de los unsigned int %u y de los punteros que se localizan mediante números hexadecimales, como el siguiente puntero %p. Finalmente la respuesta a todo son %d de posibilidades que acaban resultando como el número mágico %i\n", 'T', 'X', 'T', "42 Telefónica", 0xA5B, 0xFF, -1500, &ptr, 1000000, 42);
	ft_printf("Ha contabilizado %d caracteres\n\n", result7);

	printf("-------Prueba PRINTF ORIGINAL-------\n\n");

	result1= printf("Mi nombre es %s, y la primera letra es la %c\n", "Diego", 'D');
	printf("Ha contabilizado %d caracteres\n\n", result1);

	result2 = printf("La dirección de memoria del puntero es %p\n", &ptr);
	printf("Ha contabilizado %d caracteres\n\n", result2);

	result3 = printf("Los números mágicos son %d y %i\n", 4, 2);
	printf("Ha contabilizado %d caracteres\n\n", result3);

	result4 = printf("Un ejemplo de unsigned int sería %u\n", 42);
	printf("Ha contabilizado %d caracteres\n\n", result4);

	result5 = printf("Hexadecimal mayúscula %X y en minúscula %x\n", 0xFF, 0x2A);
	printf("Ha contabilizado %d caracteres\n\n", result5);

	result6 = printf("Prueba de %%\n");
	printf("Ha contabilizado %d caracteres\n\n", result6);

	result7 = printf("%c%c%c:Estudiamos en %s, donde estamos viendo números hexadecimales en minúsculas %x y en mayúsculas %X, aunque no nos podemos olvidar de los unsigned int %u y de los punteros que se localizan mediante números hexadecimales, como el siguiente puntero %p. Finalmente la respuesta a todo son %d de posibilidades que acaban resultando como el número mágico %i\n", 'T', 'X', 'T', "42 Telefónica", 0xA5B, 0xFF, -1500, &ptr, 1000000, 42);
	printf("Ha contabilizado %d caracteres\n\n", result7);

	return (0);
}